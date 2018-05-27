#include<iostream>
#include<memory>
using namespace std;
class demo{
  int *ptr;
  int x;
public:
  demo(int *p=NULL,int xx):ptr(p),x(xx){
    cout<<"ctor called *p  "<<p<<"\n";
  }
  int* deref(){
    return ptr;
  }
  int &ref(){
    return *ptr;
  }
  void set(int n){
    *ptr=n;
  }
  int get(){
    return *ptr;
  }
  /*demo(const demo &obj){

  }*/
  ~demo(){
    cout<<"dtor called\n";
    //delete ptr;
  }
};
int main(){
  int *n=new int();
  demo obj(n);
  obj.set(10);
  cout<<"obj.get "<<obj.get()<<"\n";
  demo obj1=obj;
  cout<<"obj1 copy ctor "<<obj1.get()<<"\n";
  demo obj2;
  obj2=obj;
  cout<<"obj2 assgn = "<<obj2.get()<<"\n";
  obj2.set(20);
  //delete obj;
  cout<<"obj2 assgn = "<<obj2.get()<<"\n";
  cout<<"obj1 after messing obj2 "<<obj1.get()<<"\n";
  cout<<"obj after messing obj2 "<<obj.get()<<"\n";
}
