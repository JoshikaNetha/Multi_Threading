#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // Create a mutex

void printNumbers(int id) {
    // Lock the mutex to protect shared resource
    mtx.lock();  
    for (int i = 1; i <= 50; ++i) {
        std::cout << "Thread " << id << ": " << i << std::endl;
    }
    // Unlock the mutex after the critical section
    mtx.unlock(); 
}

int main() {
    std::thread t1(printNumbers, 1);  // Start thread 1
    std::thread t2(printNumbers, 2);  // Start thread 2

    t1.join();  // Wait for thread 1 to finish
    t2.join();  // Wait for thread 2 to finish

    return 0;
}
/*Summary:

    A mutex is a lock that ensures only one thread can access a shared resource at a time.
    It helps avoid conflicts when multiple threads are trying to use the same data, preventing race conditions.*/
