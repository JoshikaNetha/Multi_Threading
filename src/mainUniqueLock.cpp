#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable cv;
/*std::condition_variable cv: A condition variable (cv) is used for thread synchronization. 
The producer thread signals to the consumer thread when data is ready, and the consumer waits 
until it's notified by the producer.*/
std::queue<int> dataQueue;  // Shared data between producer and consumer
bool finished = false;      // Signal when the producer is done
using namespace std;
// Producer function
void producer() {
    for(int i=1;i<=5;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));  
        unique_lock<mutex> lock(mtx);
        cout<<"Produced : "<<i<<endl;
        dataQueue.push(i);
        lock.unlock();
        cv.notify_one();
    }
    unique_lock<mutex> lock(mtx);
    finished = true;
    lock.unlock();
}

// Consumer function
void consumer() {
    while (true) {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [] { return !dataQueue.empty() || finished; });
    /*
     The consumer waits on the condition variable (cv). 
    It will only continue when either dataQueue is not empty (meaning data is available) or 
    when finished is true (meaning the producer has finished producing data).*/
    while(!dataQueue.empty()){
        int data=dataQueue.front();
        dataQueue.pop();
        cout<<"Consumer : "<<data<<endl;
    }
    if(dataQueue.empty() && finished){
        break;
    }
  }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
