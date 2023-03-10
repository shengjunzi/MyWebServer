#ifndef ACCEPTOR_H
#define ACCEPTOR_H
#include<functional>
class EventLoop;
class Socket;
class InetAddress;
class Channel;


class  Acceptor
{
private:
    EventLoop *loop;
    Socket *sock;
    std::function<void(Socket*)> newConnectionCallback;
    Channel *acceptChannel;
public:
     Acceptor(EventLoop *_loop);
    ~Acceptor();
    void acceptConnection();
    void setNewConnectionCallback(std::function<void(Socket*)>);
};
#endif