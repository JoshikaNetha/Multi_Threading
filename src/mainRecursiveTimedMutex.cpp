#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::recursive_timed_mutex rt_mtx;

void recursiveTimedFunction(int count) {
    if (count <= 0) return;

    if (rt_mtx.try_lock_for(std::chrono::milliseconds(2000))) {
        std::cout << "Lock acquired, count: " << count << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        recursiveTimedFunction(count - 1);
        rt_mtx.unlock();
    } else {
        std::cout << "Could not acquire lock, count: " << count << "\n";
    }
}

int main() {
    std::thread t1(recursiveTimedFunction, 3);
    t1.join();

    return 0;
}
