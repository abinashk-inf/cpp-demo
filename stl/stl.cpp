#include<iostream>
#include<vector>
using namespace std;
void vec(){
  vector<int> v;
  for (int i=0;i<10;i++)
    v.push_back(i);
  vector<int> c;
  c=v;
  cout<<"v= "<<&v<<"\n";
  cout<<"c= "<<&c<<"\n";
  for (int i=0;i<10;i++){
    v[i]=v[i]+1;
    cout<<v[i]<<" ";
  }
  cout<<"\n";
  for (int i=0;i<10;i++)
    cout<<c[i]<<" ";
  cout<<"\n";
  vector<int> q;
  for (int i=0;i<10;i++)
    q.push_back(i);
  vector<int> p=q;
  cout<<"q= "<<&q<<"\n";
  cout<<"p= "<<&p<<"\n";
  for (int i=0;i<10;i++){
    q[i]=q[i]+1;
    cout<<q[i]<<" ";
  }
  cout<<"\n";
  for (int i=0;i<10;i++)
    cout<<p[i]<<" ";
  cout<<"\n";
}
int main(){
  vec();
}
