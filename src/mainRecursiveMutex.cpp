#include <iostream>
#include <thread>
#include <mutex>

std::recursive_mutex rec_mtx;  // Global recursive mutex

void recursiveFunction(int count) {
    if (count <= 0) return;
    rec_mtx.lock();
    std::cout << "Recursive function call, count: " << count << "\n";
    recursiveFunction(count - 1);
    rec_mtx.unlock();
}

int main() {
    std::thread t1(recursiveFunction, 3);
    t1.join();

    return 0;
}
