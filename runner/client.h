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
#ifndef CLIENT_H
#define CLIENT_H
#include <SFML/Network.hpp>
#include <map>
#include <utility>
#include <array>
#include <set>
#include "clock.h"


/*Host info struct*/
struct hostInfo
{
    std::string adresse;
    unsigned short port;
    std::string name;
    int playerNumber;

    std::string to_string();
};

namespace rvb {
enum Action{UP,LEFT,RIGHT,K_RELEASED,QUIT};
}

struct clientInfo{
    std::string adresse;
    unsigned short port;
    std::string name;

    std::string to_string();
};

clientInfo extractClientInfo(std::string data, int &position);
hostInfo extractHostInfo(std::string data, int& position);
int extractIntegrer(std::string data, int& position);
std::string extractString(std::string data, int& position);

class Client
{
private:

    int m_clientId=-1;
    unsigned short m_hostPort;
    sf::IpAddress m_ipHost;
    std::string m_hostName;
    sf::UdpSocket m_UdpReceveicer;
    sf::UdpSocket m_UdpSender;

    clientInfo m_info;

    int m_lastFrameCounter;
    std::string m_lastString;
    std::string m_savedLastString;

    std::vector<hostInfo> m_hosts;

public:

    Client();
    std::vector<hostInfo> getHosts() const;

    void setHost(sf::IpAddress ip, unsigned short port, std::string name);
    void connect(sf::IpAddress hostIp, unsigned short hostPort);
    void connect(const int x);
    void disconnect();
    void receive();
    void stop();
    void rebind(unsigned int port);

    void sendAction(rvb::Action act);
    void sendTicket();

    void getFrame(float &gS, std::set<std::pair<int, std::pair<float, float> > > &elemP, std::pair<int, int> &playerChar, std::set<std::pair<int, std::pair<int, int> > > &Chars);


    static const unsigned short DEFAULT_PORT=9297;
    static const int PLAYER_DEFAULT_ID = -1;
};

#endif // CLIENT_H
