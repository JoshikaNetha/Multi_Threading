#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;  // Shared variable to indicate condition

// Function for the worker thread
void worker() {
    std::unique_lock<std::mutex> lock(mtx);
    
    // Wait for the condition (while loop to handle spurious wakeups)
    cv.wait(lock, [] { return ready; });
    std::this_thread::sleep_for(std::chrono::seconds(2)); 
    
    // After being notified and verifying the condition
    std::cout << "Worker thread is proceeding after the condition is met." << std::endl;
}

int main() {
    std::thread t(worker);  // Start the worker thread

    std::cout << "Main thread is proceeding." << std::endl;
    
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulate some work in main thread

    // Notify the worker thread
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;  // Change the condition to true
    }

    std::cout << "Main thread is proceeding after the condition is met." << std::endl;
    
    cv.notify_one();  // Notify the worker thread
    
    t.join();  // Wait for the worker thread to finish

    return 0;
}
