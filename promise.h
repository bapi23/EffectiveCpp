#pragma once
#include <future>
#include <thread>

std::promise<void> prom;

void detectFunction()
{
    std::cout << "event occured\n";
    prom.set_value();
}

void waitFunction()
{
    prom.get_future().wait();
    std::cout << " on event occured\n";
}


void promise_()
{
//    std::thread t1(detectFunction);
//    std::thread t2(waitFunction);
//    t1.join();
//    t2.join();

    std::future<void> f1 = async(std::launch::async, detectFunction);
    std::future<void> f2 = async(std::launch::async, waitFunction);
}
