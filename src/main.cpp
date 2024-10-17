#include<iostream>
#include <thread>
using namespace std;
// Creation of Threads

int num = 20,x=5, y =30;

// Funtion thread
void funcThread(){
    static int var = 0;
    var++;
    thread_local int t_local = 0;
    t_local++;

    num = t_local + var;

    if (x == 5) // The "Check"
    {
    y = x * 2; // The "Act"
    cout<<"Y "<<y<<endl;
    x = y;

   // If another thread changed x in between "if (x == 5)" and "y = x * 2" above,
   // y will not be equal to 10.
    }
    /*If you want to have 'static' variables that are static within the scope of each particular thread, 
    use thread_local variables instead. Then each thread will have its own version of the static variable, and the 
    static variable will only be destroyed on thread exit. */

   cout<<"[Creating threading using function] ID "<<this_thread::get_id()<<" t_local: "<<t_local<<" num: "<<num<<endl;}

    // Lambda thread
    auto lambdaThread = []{ 
    num = 300;
    cout<<"X "<<x<<endl;
    if (x == 5) // The "Check"
    {
    y = x * 2; // The "Act"
    cout<<"Y "<<y<<endl;

   // If another thread changed x in between "if (x == 5)" and "y = x * 2" above,
   // y will not be equal to 10.
    }
    cout<<"[Creating threading using Lambda] "<<this_thread::get_id()<<" : "<<num<<endl; };

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