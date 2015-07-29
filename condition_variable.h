#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

//std::mutex m;
//std::condition_variable cv;
//std::string data;
//bool ready = false;
//bool processed = false;

//void worker_thread()
//{
//    // Wait until main() sends data
//    std::cout << "Locking function in 2 thread" << std::endl;
//    std::unique_lock<std::mutex> lk(m);
//    std::cout << "Mutex locked" << std::endl;
//    cv.wait(lk, []{return ready;});

//    // after the wait, we own the lock.
//    std::cout << "Worker thread is processing data\n";
//    data += " after processing";

//    // Send data back to main()
//    processed = true;
//    std::cout << "Worker thread signals data processing completed\n";

//    // Manual unlocking is done before notifying, to avoid waking up
//    // the waiting thread only to block again (see notify_one for details)
//    lk.unlock();
//    cv.notify_one();
//}

//int condition_varaible()
//{
//    std::thread worker(worker_thread);
//    std::cout << "thread created" << std::endl;
//    sleep(10);
//    // send data to the worker thread
//    {
//        std::lock_guard<std::mutex> lk(m);
//        data = "Example data";
//        ready = true;
//        std::cout << "main() signals data ready for processing\n";
//    }
//    cv.notify_one();

//    // wait for the worker
//    {
//        std::unique_lock<std::mutex> lk(m);
//        cv.wait(lk, []{return processed;});
//        std::cout << "processed = true and wait go ahead\n";
//    }
//    std::cout << "Back in main(), data = " << data << '\n';

//    worker.join();
//}

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


