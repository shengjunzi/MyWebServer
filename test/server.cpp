#include "EventLoop.h"
#include"Server.h"

int main() {
    EventLoop *loop = new EventLoop(); //建立事件循环
    Server *server = new Server(loop);
    loop->loop();
    return 0;
}

