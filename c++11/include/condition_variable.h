#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

enum class Worker{
    Worker1,
    Worker2,
    Worker3
};

Worker currentWorker = Worker::Worker1;
std::mutex mut;

std::condition_variable convar;
std::string data;


void worker1()
{
    std::unique_lock<std::mutex> lk(mut);
    data += "worker 1 finished";
    currentWorker = Worker::Worker2;
    lk.unlock();
    convar.notify_all();
}

void worker2()
{
    std::unique_lock<std::mutex> lk(mut);
    convar.wait(lk, [](){ return currentWorker == Worker::Worker2; });
    data += "worker 2 finished";
    currentWorker = Worker::Worker3;
    lk.unlock();
    convar.notify_all();
}

void worker3()
{
    std::unique_lock<std::mutex> lk(mut);
    convar.wait(lk, [](){ return currentWorker == Worker::Worker3; });
    data += "worker 3 finished";
}

int condition_varaible()
{
    std::thread t1(worker1), t2(worker2), t3(worker3);
    t1.join();
    t2.join();
    t3.join();
    std::cout << data << std::endl;

}


