#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::timed_mutex t_mtx;

void attemptLock(int threadID) {
    if (t_mtx.try_lock_for(std::chrono::milliseconds(100))) {
        std::cout << "Thread " << threadID << " acquired the lock\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        t_mtx.unlock();
    } else {
        std::cout << "Thread " << threadID << " could not acquire the lock\n";
    }
}

int main() {
    std::thread t1(attemptLock, 1);
    std::thread t2(attemptLock, 2);

    t1.join();
    t2.join();

    return 0;
}
