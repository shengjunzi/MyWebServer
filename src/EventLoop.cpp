#include"EventLoop.h"
#include"Epoll.h"
#include"Channel.h"
#include"ThreadPool.h"
#include<vector>

EventLoop::EventLoop() : ep(nullptr), quit(false) { //新建事件循环
    ep = new Epoll(); //建立内核时间表
    threadPool = new ThreadPool(); //建立线程池
}
EventLoop::~EventLoop() {
    delete threadPool;
    delete ep;
}
void EventLoop::loop() {
    while(!quit) {
        std::vector<Channel*> chs;
        chs = ep->poll();
        for(auto it = chs.begin(); it!=chs.end(); ++it) {
            (*it)->handleEvent();
        }
    }
}
void EventLoop::updateChannel(Channel *ch) {
    ep->updateChannel(ch);
}
void EventLoop::addThread(std::function<void()> func) {
    threadPool->add(func);
}