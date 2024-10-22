#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void thread_function(){
  lock_guard<mutex> guard(mtx); 
  cout<<"Using Mutex Lock Guard in Thread function \n";
  // Mutex automatically unlocked when lock_guard goes out of scope
}

int main(){

    cout<<"[Thread MUTEX] \n";

    thread thread_func(thread_function);
    thread_func.join();

    return 0;
}