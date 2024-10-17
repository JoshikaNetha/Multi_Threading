#include<iostream>
#include <thread>
using namespace std;
// Creation of Threads

// Funtion thread
void funcThread(){
  cout<<"[Creating threading using function] ID "<<this_thread::get_id()<<endl;
}

// Lambda thread
auto lambdaThread = []{ cout<<"[Creating threading using Lambda] "<<this_thread::get_id()<<endl; };

//Functor
class thread_Class{
    public:
    void operator()() {
        cout << "[Creating threading using Functor] "<<this_thread::get_id()<< endl;
    }

};

int main(){

    cout<<"WELCOME TO Multi-Threading "<<endl;

    unsigned int c = std::thread::hardware_concurrency();

    cout<<"Number of threads we can create "<<c<<endl;

    thread thread_function(funcThread);
    thread_function.join();

    thread thread_lambda(lambdaThread);
    thread_lambda.join();
  
    // Thread using a functor (ensure to create a proper object)
    thread_Class functor;
    thread thread_functors(functor);  // Pass the functor object to the thread
    thread_functors.join();  // Join the thread
    
    return 0;

}