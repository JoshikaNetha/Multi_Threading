#include<iostream>
#include <thread>
using namespace std;
// Creation of Threads

// Funtion thread
void funcThread(){
  cout<<"[Creating threading using function]"<<endl;
}

// Lambda thread
auto lambdaThread = []{ cout<<"[Creating threading using Lambda]"<<endl; };

//Functor
class thread_Class{
      void functors() {
        cout<<"[Creating threading using Lambda]"<<endl;
      }

};

int main(){

    thread thread_function(funcThread);
    thread_function.join();

    thread thread_function(funcThread);
    thread_function.join();

    thread thread_function(funcThread);
    thread_function.join();
    
    cout<<"WELCOME TO MULTI-THREADING TUTORIAL "<<endl;
    return 0;

}