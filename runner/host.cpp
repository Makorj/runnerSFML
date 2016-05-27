/*
Copyright (c) 2016 Florent VAIN, Thomas BLANC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:


The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#include "host.h"
#include "View.h"
#include <iostream>
#include <memory>
#include <mutex>
#include "Model.h"

using namespace std;


Host::Host()
    : m_frameCounter(0)
{
    m_info.adresse=sf::IpAddress::getLocalAddress().toString();
    m_info.port=sf::Socket::AnyPort;
    m_info.name="HostName";
    m_info.playerNumber=0;

    m_UdpTeller.setBlocking(false);
    sf::Packet p1,p2;
    p1 << pomme("100;" + m_info.to_string() +";end **");
    p2 << pomme("150;" + m_info.to_string() +";end **");

    m_packets.insert(make_pair(100, p1));
    m_packets.insert(make_pair(150, p2));
}

void Host::sendGlobal(sf::Packet data)
{
    if(m_UdpTeller.send(data,
                        sf::IpAddress::Broadcast,
                        Host::DEFAULT_PORT)!= sf::Socket::Done)
    {
        cerr << "error sending global udp packet" << endl;
    }
    if(m_UdpTeller.send(m_packets[100],
                        sf::IpAddress::Broadcast,
                        Host::DEFAULT_PORT)!= sf::Socket::Done)
    {
        cerr << "error sending global udp packet 100" << endl;
    }
    if(m_UdpTeller.send(m_packets[150],
                        sf::IpAddress::Broadcast,
                        Host::DEFAULT_PORT)!= sf::Socket::Done)
    {
        cerr << "error sending global udp packet 150" << endl;
    }
    if(_model->hasEnded())
    {
        m_frameCounter=0;
        sf::Packet p;
        p << pomme("420;" + m_info.to_string() +";dts **;"+ to_string(m_frameCounter) +";end **");
        if(m_UdpTeller.send(p,
                            sf::IpAddress::Broadcast,
                            Host::DEFAULT_PORT)!= sf::Socket::Done)
        {
            cerr << "error sending 430 packet" << endl;
        }
    }
}

void Host::setModel(Model *model)
{
    _model=model;
}

sf::Packet Host::FramePacket()
{
    sf::Packet toSend;
    string data;

    data = "530;"+ m_info.to_string() +";dts **;";
    data += to_string(m_frameCounter) +";" + to_string(_model->getAllSpeed()) +";";

    std::pair<float,float> pos = _model->getBallPosition();
    data+="po **;" + to_string(1001) +";"+ to_string(_model->getLife()) +";"+   to_string(((int)(pos.first))) +";"+  to_string(((int)(pos.second))) +";";

    std::map<int, std::shared_ptr<Character> >* p = _model->getMultiCharData();

    if(!p->empty())
    {
        for(int x : m_playersIds)
        {
            Character z = *(p->at(x).get());
            data+= "po **;" + to_string(x) +";"+ to_string(z.getLife()) +";"+  to_string(((int)(z.getX()))) +";"+  to_string(((int)(z.getY()))) +";";
        }
    }

    std::set<std::pair<int, std::pair<float, float> > > elemPos;
    _model->getElemsPos(elemPos);

    for(auto x : elemPos)
    {
        data+= "no **;" + to_string(x.first) +";"+ to_string((int)(x.second.first)) +";"+ to_string((int)(x.second.second)) +";";
    }

    data += "end **";

    m_frameCounter++;
    toSend << pomme(data);
    return toSend;

}

void Host::rebind(unsigned short port)
{
    if(m_UdpTeller.bind(port) != sf::Socket::Done)
    {
        cout << "Error udp host binding" << endl;
    }
}

Host::~Host()
{
    for(auto x : m_PlayersSockets)
    {
        delete x.second.second;
    }
}

void Host::receive()
{
    sf::Packet recei;
    string data;
    sf::IpAddress Ip;
    unsigned short port;
    if(m_UdpTeller.receive(recei,Ip,port)==sf::Socket::Done)
    {
        if(recei >> data)
        {
            data = pomme(data);
            //Connection demand from client
            if(data.find("200;") == 0 )
            {
                clientInfo client;
                hostInfo host;
                int actualPos(0);
                bool present=false;

                host = extractHostInfo(data, actualPos);

                if(!(host.adresse == m_info.adresse
                     && host.name == m_info.name
                     && host.adresse == m_info.adresse
                     && host.port == m_info.port))
                    present=true;

                if(!present)
                    for(auto x : m_playersIds)
                    {
                        if(m_playersInfo[x].adresse == Ip.toString())
                            present=true;
                    }

                if(!present)
                {
                    int id = 1000+(rand()%150);
                    while(m_playersIds.find(id)!=m_playersIds.end() && id!=1001)
                    {
                        id = 1000+(rand()%150);
                    }
                    m_playersIds.insert(id);

                    client=extractClientInfo(data, actualPos);

                    if(data.substr(actualPos+1) == "end **")
                    {
                        m_playersInfo.insert(make_pair(id,client));
                        m_playersActions.insert(make_pair(id, make_pair(false, false)));
                        m_PlayersSockets.insert(make_pair(id,make_pair(sf::Socket::AnyPort, new sf::UdpSocket())));
                        (m_PlayersSockets[id].second)->setBlocking(false);
                        _model->getMultiCharData()->insert(make_pair(id,std::make_shared<Character> ((float)10.,
                                                                     (float)450.,
                                                                     (int)125,
                                                                     (int)90,
                                                                     (float)0.,
                                                                     (float)0.,
                                                                     0,
                                                                     100)));

                        if((m_PlayersSockets[id].second)->bind(m_PlayersSockets[id].first) != sf::Socket::Done)
                        {
                            cerr << "Error socket binding on port " << m_PlayersSockets[id].first << endl;
                        }
                        else
                        {
                            sf::Packet p;
                            p << pomme("201;" + m_info.to_string() +";"+ to_string(id)+";"+ to_string(m_PlayersSockets[id].first) +";"+ to_string(m_frameCounter) +";end **");
                            if((m_PlayersSockets[id].second)->send(p, Ip, Client::DEFAULT_PORT)!=sf::Socket::Done)
                            {
                                cerr << "error send conf 201" << endl;
                            }
                        }
                    }
                }
                else
                {
                    if(m_UdpTeller.send(m_packets[205],Ip,Client::DEFAULT_PORT)!=sf::Socket::Done)
                    {
                        cerr << "Error sending packet 205" << endl;
                    }
                }
            }
            //client confirmation from connection
            else if (data.find("210;") == 0)
            {
                clientInfo client;
                int actualPos(0);

                client=extractClientInfo(data,actualPos);

                int id=1002;
                while(client.adresse!=m_playersInfo[id].adresse
                      && client.port!=m_playersInfo[id].port
                      && client.name!=m_playersInfo[id].name)
                {
                    id++;
                }

            }
            else if(data.find("222;")==0)
            {
                clientInfo client;
                int actualPos(0);

                client = extractClientInfo(data, actualPos);
                int id= extractIntegrer(data,actualPos);

                if(m_playersIds.find(id)!=m_playersIds.end())
                {
                    if(client.adresse==m_playersInfo[id].adresse
                            && client.port==m_playersInfo[id].port
                            && client.name==m_playersInfo[id].name)
                    {
                        m_playerTimedOut.at(id).restart();
                    }

                }

            }
            //Client ask for disconnection
            else if (data.find("250;")==0)
            {
                clientInfo client;
                int actualPos(0);

                client=extractClientInfo(data, actualPos);

                int id = extractIntegrer(data, actualPos);

                if(m_playersIds.find(id)!=m_playersIds.end())
                {

                    sf::Packet p;
                    p << pomme("251;" + m_info.to_string() +";"+ to_string(id) +";end **");
                    if((m_PlayersSockets[id].second)->send(p, Ip, Client::DEFAULT_PORT)!=sf::Socket::Done)
                    {
                        cerr << "error send conf 251" << endl;
                    }

                   m_playerDisconnect.insert(id);
                }
            }
            //client actions
            else if (data.find("310;")== 0)
            {
                clientInfo client;
                int actualPos(0);

                client = extractClientInfo(data,actualPos);

                int id = extractIntegrer(data, actualPos);

                if(m_playersIds.find(id)!=m_playersIds.end())
                {
                    std::map<int, std::shared_ptr<Character> >* p = _model->getMultiCharData();
                    std::string text = extractString(data, actualPos);
                    if(text=="dts **")
                    {

                        int action = extractIntegrer(data, actualPos);
                        switch(action)
                        {
                        case rvb::Action::UP:
                            p->at(id)->isJumping();
                            break;
                        case rvb::Action::LEFT:
                            m_playersActions.at(id)=make_pair(true,false);
                            break;
                        case rvb::Action::RIGHT:
                            m_playersActions.at(id)=make_pair(false,true);
                            break;
                        case rvb::Action::QUIT:
                            break;
                        case rvb::Action::K_RELEASED:
                            m_playersActions.at(id)=make_pair(false,false);
                            break;
                        default:
                            break;
                        }
                    }
                }
            }

        }
    }
}

std::map<int, std::pair<bool, bool> >* Host::getPlayersActions()
{
    return &m_playersActions;
}

std::set<int>* Host::getPlayersIds()
{
    return &m_playersIds;
}

std::map<int, clientInfo>* Host::getPlayersInfo()
{
    return &m_playersInfo;
}

void Host::delDisconnectedPlayer()
{
    if(!m_playerDisconnect.empty())
    {
        for(auto id : m_playerDisconnect)
        {
            m_playersInfo.erase(id);
            m_PlayersSockets.erase(id);
            _model->getMultiCharData()->erase(id);
            m_playersIds.erase(id);
        }
    }
}

void Host::stop()
{
    m_UdpTeller.unbind();
}

