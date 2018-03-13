#include<iostream>
#include<thread>

using namespace std;

void foo(int Z){
    for(int i=0;i<Z;i++)
    cout<<"testing pointer callable\n";
}

// callable object
class thread_obj{
    public:
    void operator()(int x){
        for(int i=0;i<x;i++)
        cout<<"testing object as callable\n";
    }
};
int main(){
    cout<<"thread 1,2,3 working independently"<<endl;
    //thread launched using function pointer callable
    thread th1(foo,3);
    //thread launched using function object callable
    thread th2(thread_obj(),3);

    //defining using lambda expression
    auto f=[](int x){
        for(int i=0;i<x;i++)
        cout<<"testing using lamda as callable\n";
    };

    thread th3(f,3);

    th1.join();
    th2.join();
    th3.join();
return 0;
}