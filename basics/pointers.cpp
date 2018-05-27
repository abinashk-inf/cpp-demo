#include<iostream>
#include<memory>
using namespace std;

class demo{
  int ptr;
public:
  demo(){
    ptr=0;
  }
  //demo(int p=0):ptr(p){}
  /*int* deref(){
    return ptr;
  }
  int &ref(){
    return *ptr;
  }*/
  void set(int n){
    ptr=n;
  }
  int get(){
    return ptr;
  }

};
void smart(){

}
int main(){
/*  int *p1,*p2;
  p1=new int();
  *p1=10;
  cout<<" dereferncing p1  "<<*p1<<"\n";
  cout<<" p1 address  "<<p1<<"\n";
  p2=p1;
  *p2=20;
  cout<<" p2 address  "<<p2<<"\n";
  cout<<"the val of p2  "<<*p2;
  cout<<" dereferncing p1  "<<*p1<<"\n";
*/
  /*char *c1="abc";
  cout<<" dereferncing c1  "<<*c1<<"\n";
  cout<<" adress c1  "<<c1<<"\n";
  struct node {
    int n;
    char c;
  };
  typedef struct node N;
  N x;
  N *xp;
  xp=&x;
  //cout<<" dereferncing struct &x  "<<&x<<"\n";
  //cout<<" dereferncing struct xp  "<<xp<<"\n";
  //cout<<" dereferncing struct *xp  "<<(*xp)<<"\n";
  int *i=new int();
  char *c=new char();
  float *f=new float;
  cout<<"the val of *i  "<<*i<<"\n";
  cout<<"the val of *c  "<<*c<<"\n";
cout<<"the val of *f  "<<*f<<"\n";
*/

/*int *n=new int();
demo obj(n);
obj.set(5);
int x=obj.ref();
cout<<"int* deref  "<<obj.deref()<<"\n";
//x=obj.ref();
cout<<"int& ref  "<<obj.ref()<<"\n";
x++;
cout<<"int get(){  "<<obj.get()<<"\n";
cout<<"x=  "<<x<<"\n";
*/
unique_ptr<demo> p(new demo());
p->set(5);
cout<<"p "<<p->get()<<"\n";
unique_ptr<demo> q;
q=p;
p->set(6);
q->set(7);
cout<<"p "<<p->get()<<"\n";
cout<<"q "<<q->get()<<"\n";

}
