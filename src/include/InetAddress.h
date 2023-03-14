#ifndef INETADRESS_H
#define INETADDRESS_H
#include<arpa/inet.h>
class InetAddress
{
private:
    /* data */
public:
    struct sockaddr_in addr;
    socklen_t addr_len;
    InetAddress(/* args */);
    InetAddress(const char* ip, uint16_t port);
    ~InetAddress();
    void setInetAddr(sockaddr_in _addr);
    sockaddr_in getAddr();
};

#endif