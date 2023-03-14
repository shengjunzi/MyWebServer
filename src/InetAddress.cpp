#include"InetAddress.h"
#include<string.h>
InetAddress::InetAddress()  {
    bzero(&addr, sizeof(addr));
}
InetAddress::InetAddress(const char *ip, uint16_t port) {
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip); 
    //inet_pton(AF_INET, ip, addr.sin_addr.s_addr )
    addr.sin_port = htons(port); //h - host, 主机字节序； to; n - network ,网络字节序； s - short
}
    
InetAddress::~InetAddress() {
    
}
void InetAddress::setInetAddr(sockaddr_in _addr){
    addr = _addr;
}

sockaddr_in InetAddress::getAddr(){
    return addr;
}