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
#ifndef HOST_H
#define HOST_H
#include <SFML/Network.hpp>

#include <map>
#include <set>
#include "client.h"

class Model;

class Host
{
private:
    sf::UdpSocket m_UdpTeller;

    hostInfo m_info;
    int m_frameCounter;

    Model* _model;
    std::map<int, sf::Packet> m_packets;
    std::map<int, clientInfo> m_playersInfo;
    std::map<int, std::pair<bool,bool> > m_playersActions;
    std::map<int, std::pair<unsigned int, sf::UdpSocket *> > m_PlayersSockets;
    std::set<int> m_playersIds;
    std::set<int> m_playerDisconnect;
    std::map<int, Clock> m_playerTimedOut;


public:
    Host();
    void sendGlobal(sf::Packet data);
    ~Host();

    std::map<int, std::pair<bool,bool> >* getPlayersActions();
    std::set<int>* getPlayersIds();
    std::map<int, clientInfo>* getPlayersInfo();

    sf::Packet FramePacket();
    void receive();
    void setModel(Model* model);
    void delDisconnectedPlayer();
    void rebind(unsigned short port);

    void stop();


    static const unsigned short DEFAULT_PORT=9297;
};

#endif // HOST_H


/*



STATIC CONST DE PACKET PAR DEFAUTS
            CONFIRMATION DE RECEPTION DE TRUCS










*/
