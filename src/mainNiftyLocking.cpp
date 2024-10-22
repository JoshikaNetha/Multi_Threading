#include <iostream>
#include <mutex>
#include <thread>
class Singleton {
private:
    static Singleton* instance;   // Singleton instance
    static std::mutex mtx;        // Mutex to protect initialization

    // Private constructor to prevent instantiation
    Singleton() {
        std::cout << "Singleton instance created" << std::endl;
    }

public:
    // Static method to get the singleton instance
    static Singleton* getInstance() {
        if (instance == nullptr) {         // First check without locking
            std::lock_guard<std::mutex> lock(mtx);  // Acquire lock

            if (instance == nullptr) {     // Second check after locking
                instance = new Singleton();  // Create the singleton instance
            }
        }
        return instance;
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

int main() {
    // Create two threads trying to access the singleton instance
    std::thread t1([]() { Singleton* s1 = Singleton::getInstance(); });
    std::thread t2([]() { Singleton* s2 = Singleton::getInstance(); });

    t1.join();
    t2.join();

    return 0;
}
