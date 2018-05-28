#include <iostream>
#include "smartpointer.h"

using namespace std;

demo::demo():p(0){}
demo::demo(int pp):p(pp){}
void demo::show(){
  cout<<"the current value is "<<p<<"\n";
}
void demo::set(int x){
  p=x;
}

int main(){
  if (1){
    smart_ptr<demo> ptr(new demo());
    ptr->show();
    (*ptr).set(5);
    ptr->show();
  }
  //ptr->show() //compiler error
}
