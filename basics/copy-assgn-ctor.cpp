#include <iostream>
using namespace std;

class demo{
  string str;

  public:
  demo():str(""){
    cout<<"*this and this"<<"   "<<(this)<<"\n";
  }
  demo(string st):str(st){}
  demo(const demo &obj){
    cout<<"copy ctor\n";
    str=obj.str;
  }
  //if no ref, this will call copy ctor again.
  demo& operator=(const demo &obj){
    cout<<"assignment operator \n";
    //to avoid self copy
    if(this!=&obj){   //*this does not have != operator
      this->str=obj.str;
    }
    return *this;
  }
};
int main(){
  demo obj1("obj1");
  demo obj2=obj1; //copy
  demo obj3("obj3");
  demo obj4;
  obj4=obj3; //assignment
}
