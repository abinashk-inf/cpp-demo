#include <iostream>
using namespace std;
class base{
  int m_data;
  public:
  base():m_data(0)
  {
    cout<<"default ctor\n";
  }
  base(int data):m_data(data){
    cout<<"para ctor\n";
  }
  void disp(){
    cout<<"the value of n is"<<m_data<<"\n";
  }
};
class der:public base{
  int md_data;
  public:
  der():base(0),md_data(0)
  {
    cout<<"default der ctor\n";
  }
  der(int data):base(data),md_data(data){
    cout<<"para der ctor\n";
  }
  void disp(){
    cout<<"the value of n is"<<md_data<<"\n";
  }
};
int main(){
  //demo obj;
  der d(20);
  base *ptr=&d;

}
