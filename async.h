#pragma once
#include <future>
#include <limits>
#include <pthread.h>
#include <unistd.h>

using namespace std::literals;


int fun()
{
    std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
    return 15;
}

int fun_long()
{
//    for(int i = 0; i < std::numeric_limits<int>::max(); ++i)
//    {
//        if(i%10000 == 0)
//        {
//            std::cout << "pozdrowienia z wątku: " << std::this_thread::get_id() << " iteracja :" << i << std::endl;
//        }
//    }
    return 0;
}

void async()
{
    std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;
    std::future<int> fut = std::async(fun);
    std::cout << "thread deffered | async: " << std::endl;
    int result = fut.get();
    std::cout << "Future result:" << result << std::endl;

    std::cout << "thread async | sync: " << std::endl;
    std::future<int> fut_asynch = std::async(std::launch::async, fun_long);
    int result2 = fut_asynch.get();

    std::cout << "thread deffered: " << std::endl;
    std::future<int> fut_deffered = std::async(std::launch::deferred, fun_long);
    std::cout << "is deffered? :" << bool(fut_deffered.wait_for(0s) == std::future_status::deferred) << std::endl;
    int result3 = fut_deffered.get();

    std::cout << "thread1: " << std::endl;
    std::thread t(fun);

    std::cout << "thread2: " << std::endl;
    std::thread t2(fun);

    t.join();
    t2.join();
}
