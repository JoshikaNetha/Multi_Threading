#include <iostream>
#include <thread>
#include <shared_mutex>
using namespace std;
std::shared_timed_mutex sharedMtx;
int data = 0;  // Shared resource

void reader(int threadID) {
    std::shared_lock<std::shared_timed_mutex> lock(sharedMtx);  // Lock in shared mode
    std::cout << "Reader " << threadID << " reads data: " << data << "\n";
}

void writer(int threadID) {
    std::unique_lock<std::shared_timed_mutex> lock(sharedMtx);  // Lock in exclusive mode
    data += threadID;
    std::cout << "Writer " << threadID << " modifies data to: " << data << "\n";
}

int main() {

    std::thread t2(writer, 2);
    std::thread t1(reader, 1);
    std::thread t3(reader, 3);
    std::thread t4(reader, 4);
    std::thread t5(reader, 5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}
