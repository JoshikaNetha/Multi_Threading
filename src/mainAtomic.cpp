#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
using namespace std;
std::atomic<int> counter(0);  // Shared atomic counter

void incrementCounter() {
    for (int i = 0; i < 1000; ++i) {
        counter++;  // Atomically increment the counter
    }
}

int main() {
    std::vector<std::thread> threads;

    // Launch 10 threads that increment the counter
    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread(incrementCounter));
    }

    // Join all the threads
    for (auto &th : threads) {
        th.join();
    }

    // Print the final value of the counter
    std::cout << "Final Counter Value: " << counter << std::endl;

    return 0;
}
