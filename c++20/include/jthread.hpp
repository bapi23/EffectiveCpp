#include <thread>
#include <iostream>

void do_work(){
    using namespace std::chrono_literals;

    std::cout << "doing work on thread" << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(2000ms);
}

void do_work2(std::stop_token token){
    while (!token.stop_requested()){
        std::cout << "running in thread: " << std::this_thread::get_id() << std::endl;

    }
}

void jthread_test(){
    using namespace std::chrono_literals;
    std::jthread thread1(do_work2);
    std::this_thread::sleep_for(2000ms);
    thread1.request_stop();
    std::this_thread::sleep_for(100ms);
}