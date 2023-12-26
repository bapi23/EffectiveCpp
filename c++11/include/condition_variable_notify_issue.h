#include <iostream>
#include <deque>
#include <condition_variable>
#include <thread>

std::deque<int> q;
std::mutex m;
std::condition_variable cv;

void dump_q()
{
    for (auto x: q) {
        std::cout << x << std::endl;
    }
}

void producer()
{
    for(int i = 0; i < 10; i++) {
        std::unique_lock<std::mutex> locker(m);
        q.push_back(i);
        std::cout << "produced: " << i << std::endl;
        locker.unlock();

        cv.notify_one();
    }
}

void consumer()
{
    int data = 0;
    std::unique_lock<std::mutex> locker(m); 
    //cv.wait(locker);
    cv.wait(locker, [](){return !q.empty();});  // <- this fixes both spurious and lost wakeups
    

    while (!q.empty()){
        data = q.front();
        std::cout << "--> consumed: " << data << std::endl;
        q.pop_front();
    }
    
    locker.unlock();
}

void condition_variable_tests2()
{
    std::thread t1(producer);
    std::this_thread::sleep_for(std::chrono::seconds(5));   // <- should miss first 5 notications?

    std::thread t2(consumer);
    t1.join();
    t2.join();
}