#include "client.h"
#include <iostream>
#include <set>
#include <Model.h>
#include <SFML/Network.hpp>

using namespace std;
volatile bool lastStringIsAvailable=true;

std::string hostInfo::to_string(){
    return adresse +";"+ std::to_string(port) +";"+ name +";"+ std::to_string(playerNumber);
}

std::string clientInfo::to_string()
{
    return adresse +";"+ std::to_string(port) +";"+ name;
}

Client::Client()
{
    m_info.adresse=sf::IpAddress::getLocalAddress().toString();
    m_info.port=DEFAULT_PORT;
    m_info.name="ClientNAme";
    if(m_UdpReceveicer.bind(DEFAULT_PORT) != sf::Socket::Done)
    {
        cerr << "Client unable to bind udp receiver" << endl;
    }
    m_UdpReceveicer.setBlocking(false);
}

std::vector<hostInfo> Client::getHosts() const
{
    return m_hosts;
}

void Client::sendTicket()
{
    string text = "222;" + m_info.to_string() +";"+ to_string(m_clientId) + ";end **";
    sf::Packet data;
    data << pomme(text);
    if(m_UdpReceveicer.send(data,sf::IpAddress::Broadcast,DEFAULT_PORT)!=sf::Socket::Done)
    {
        cerr << "errrrr" << endl;
    }
}

void Client::sendAction(Action act)
{
    string text = "310;" + m_info.to_string() +";"+ to_string(m_clientId) + ";dts **;" + to_string(act) + ";end **";
    sf::Packet data;
    data << pomme(text);
    if(m_UdpReceveicer.send(data,sf::IpAddress::Broadcast,DEFAULT_PORT)!=sf::Socket::Done)
    {
        cerr << "errrrr" << endl;
    }
}

void Client::getFrame(float &gS, std::set<std::pair<int, std::pair<float, float> > > &elemP, std::pair<int, int> &playerChar, std::set<std::pair<int, std::pair<int, int> > > &Chars)
{
    string data=m_lastString;

    if(!lastStringIsAvailable)
    {
        data=m_savedLastString;
    }

    if(!data.empty())
    {
        int actualPos = -1;
        //Global Speed
        gS = extractIntegrer(data,actualPos);

        //Player Object (characters sprites)
        while(data.find("po **;",actualPos)!=string::npos)
        {
            extractString(data,actualPos);

            int id = extractIntegrer(data, actualPos);

            //Character's life
            int life = extractIntegrer(data, actualPos);
            //Character Position
            int x = extractIntegrer(data, actualPos);
            int y = extractIntegrer(data, actualPos);

            //If it's the client's character
            if(id==m_clientId)
            {
                playerChar = make_pair(x,y);
            }
            //otherwise
            else
            {
                Chars.insert(make_pair(id,make_pair(x,y)));
            }
        }

        //Environnement objects (Obstacles, bonuses...)
        while(data.find("no **;",actualPos)!=string::npos)
        {
            extractString(data,actualPos);
            int id = extractIntegrer(data, actualPos);
            cout << id << endl;
            int a = extractIntegrer(data, actualPos);
            int b = extractIntegrer(data, actualPos);

            elemP.insert(make_pair(id,make_pair(a,b)));
        }

        m_savedLastString=data;
    }
}

void Client::receive() {
    sf::Packet packet;
    string data;
    sf::IpAddress ip;
    unsigned short port;
    if(m_UdpReceveicer.receive(packet, ip, port)==sf::Socket::Done)
    {
        if(packet >> data)
        {
            data=pomme(data);

            if((data.find("100;") == 0) && m_clientId==PLAYER_DEFAULT_ID)
            {
                hostInfo host;
                int actualPos(0);

                host = extractHostInfo(data, actualPos);

                if(data.substr(actualPos+1) == "end **" && host.name!=m_hostName)
                {
                    bool newHost=true;
                    for(hostInfo x : m_hosts)
                        if(x.adresse==host.adresse && x.name==host.name && x.port==host.port)
                            newHost=false;
                    if(newHost)
                        m_hosts.push_back(host);

                    //connect(ip,host.port, host.name);
                }
            }
            else if(data.find("201;")==0)
            {

                hostInfo host;
                int actualPos(0);

                host = extractHostInfo(data, actualPos);


                //Testing Confirmation Message sender identity matching with actual host
                if((m_ipHost.toString()==host.adresse))
                {
                    m_clientId = extractIntegrer(data,actualPos);

                    m_hostPort = extractIntegrer(data,actualPos);

                    m_lastFrameCounter = extractIntegrer(data, actualPos);

                    setHost(m_ipHost,m_hostPort,m_hostName);

                    m_lastString.clear();
                    m_savedLastString.clear();
                }

            }
            else if(data.find("205;")==0)
            {

            }
            else if(data.find("251;")==0)
            {
                hostInfo host;
                int actualPos(0);
                host = extractHostInfo(data, actualPos);

                int id = extractIntegrer(data, actualPos);

                if(id==m_clientId)
                {
                    cout << "pommmmemeee" << endl;
                    m_clientId=PLAYER_DEFAULT_ID;
                    m_hostPort=0;
                    m_ipHost=sf::IpAddress::None;
                    m_hostName.clear();
                    m_UdpReceveicer.bind(DEFAULT_PORT);
                    m_UdpSender.bind(DEFAULT_PORT);
                    m_lastFrameCounter=0;
                    m_hosts.clear();
                }
            }
            else if(data.find("530;")==0)
            {
                hostInfo host;
                int actualPos(0);

                host = extractHostInfo(data, actualPos);

                if(ip.toString()==host.adresse || m_ipHost.toString()==host.adresse || true)
                {
                    std::string value = extractString(data,actualPos);
                    if("dts **" == value)
                    {
                        int frame = extractIntegrer(data, actualPos);
                        if(m_lastFrameCounter<frame)
                        {
                            lastStringIsAvailable = false;
                            m_lastFrameCounter=frame;
                            std::string tmp = data.substr(actualPos+1);
                            m_lastString = (tmp.empty()?m_lastString:tmp);
                            lastStringIsAvailable = true;
                        }
                    }
                }
            }
            else if(data.find("420;")==0)
            {
                hostInfo host;
                int actualPos(0);

                host = extractHostInfo(data, actualPos);

                if(ip.toString()==host.adresse || m_ipHost.toString()==host.adresse || true)
                {
                    std::string value = extractString(data, actualPos);
                    if("dts **" == value)
                    {
                        int frame = extractIntegrer(data, actualPos);
                        if(frame<=m_lastFrameCounter)
                            m_lastFrameCounter=frame;
                    }
                }
            }
        }
    }
}

void Client::setHost(sf::IpAddress ip, unsigned short port, std::string name)
{
    sf::Packet data;
    m_ipHost = ip;
    m_hostPort= port;
    m_hostName=name;
    data << pomme("210;" + m_info.to_string() +";end **");

    if(m_UdpReceveicer.send(data,sf::IpAddress::Broadcast,DEFAULT_PORT)!=sf::Socket::Done)
    {
        cerr << "errrrr" << endl;
    }
}

void Client::connect(sf::IpAddress ip, unsigned short port, std::string name)
{
    sf::Packet data;
    m_ipHost=ip;
    data << pomme("200;" + m_info.to_string() +";end **");

    if(m_UdpReceveicer.send(data,sf::IpAddress::Broadcast,DEFAULT_PORT)!=sf::Socket::Done)
    {
        cerr << "errrrr" << endl;
    }


}

void Client::disconnect()
{
    sf::Packet data;
    data << pomme("250;" + m_info.to_string() +";"+ to_string(m_clientId) +";end **");

    if(m_UdpReceveicer.send(data,sf::IpAddress::Broadcast, DEFAULT_PORT)!=sf::Socket::Done)
    {
        cerr << "errrrr" << endl;
    }
}

hostInfo extractHostInfo(std::string data, int& position)
{
    hostInfo host;
    int actualPos=position+3;
    int nextPos = data.find(';',actualPos+1);
    host.adresse = data.substr(actualPos+1,nextPos-actualPos-1);
    actualPos = nextPos;
    nextPos = data.find(';',actualPos+1);
    host.port = stoi(data.substr(actualPos+1,nextPos-actualPos-1));
    actualPos = nextPos;
    nextPos = data.find(';', actualPos+1);
    host.name = data.substr(actualPos+1,nextPos-actualPos-1);
    actualPos = nextPos;
    nextPos = data.find(';', actualPos+1);
    host.playerNumber = stoi(data.substr(actualPos+1,nextPos-actualPos-1));

    position = nextPos;
    return host;
}

clientInfo extractClientInfo(std::string data, int &position)
{
    clientInfo client;

    int actualPos = data.find(';',4+1);
    client.adresse = data.substr(4,actualPos-4);
    int nextPos = data.find(';',actualPos+1);
    client.port = stoi(data.substr(actualPos+1,nextPos-actualPos-1));
    actualPos = nextPos;
    nextPos = data.find(';', actualPos+1);
    client.name = data.substr(actualPos+1,nextPos-actualPos-1);

    position=nextPos;
    return client;
}

int extractIntegrer(std::string data, int& position)
{
    int actualPos=position;
    int nextPos=data.find(';', actualPos+1);
    int value = stoi(data.substr(actualPos+1,nextPos-actualPos-1));
    position = nextPos;
    return value;
}

std::string extractString(std::string data, int& position)
{
    int actualPos=position;
    int nextPos=data.find(';', actualPos+1);
    std::string value = data.substr(actualPos+1, nextPos-actualPos-1);
    position = nextPos;
    return value;
}
