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

enum Action{UP,LEFT,RIGHT,K_RELEASED, QUIT};

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
    void connect(sf::IpAddress hostIp, unsigned short hostPort, std::string name);
    void disconnect();
    void receive();

    void sendAction(Action act);
    void sendTicket();

    void getFrame(float &gS, std::set<std::pair<int, std::pair<float, float > > > & elemP, std::pair<int,int>& playerChar, std::set<std::pair<int, std::pair<int,int> > > & Chars);



    static const unsigned short DEFAULT_PORT=92974;
    static const int PLAYER_DEFAULT_ID = -1;
};

#endif // CLIENT_H
