#include <iostream>
#include <map>
#include<vector>
#include<ctime>
using namespace std;
/*
class demo{
  string slot;
  string reg;
  //demo(){}
  public:
  demo():reg(""),slot(""){}
  demo(string r,string s):reg(r),slot(s){}
  void disp(){
    cout<<"The vehicle reg  "<<reg<<"\n";
    cout<<"The vehicle slot "<<slot<<"\n";
  }
};
class trial{
  map<int,vector<int>>mp;
public:
  //trial():mp(){}
  void addfloor(int s,int m,int l){
    int c=mp.size();
    vector<int>v={s,m,l};
    //mp.insert(make_pair<int,vector<int>>(c,{s,m,l}));
    mp.insert(make_pair(c,v));
  }
  void disp(){
    //auto it=mp.begin();
    for (auto it=mp.begin();it!=mp.end();++it){
      cout<<it->first<<"  ";
      for(int i=0;i<(it->second).size();++i)
      cout<<(it->second)[i]<<"  ";
      cout<<"\n";
    }
  }
};
*/
class demo{

public:
  //demo(int xx):x(xx){}
  int x;
  demo():x(0){std::cout << "demo ctor"<< '\n';}
  virtual void show(){ std::cout << x << '\n';}
  demo(int xx):x(xx){{ std::cout << x << '\n';}}
};
class demohandler: public demo{
  int y;
public:
  demohandler(int yy):y(yy){{std::cout << "demohadler ctor"<< '\n';}}
  void show(){ std::cout << y << '\n';}
};
int count(){
  static int c=0;
  c++;
  std::cout << c << '\n';
}
int main(){
  /*demo obj;
  obj.disp();
  demo obj1("5072","medium");
  obj1.disp();
  */
  /*
  trial obj;
  obj.addfloor(10,20,30);
  obj.addfloor(30,40,50);
  obj.disp();
*/
demo *obj=new demohandler(5);
//obj->show();
}
