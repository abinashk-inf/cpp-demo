#include<iostream>
#include<map>
#include<vector>
#include<ctime>
#include<exception>
#include"singleton.h"
using namespace std;

/*class demo{
  static demo* inst[6];
  static int id;
  demo(){}
  public:
  static demo* getinst(int i=id){
    if(i>=5||id>=5){
      throw logic_error("cannnot create more than five objects");
    }
    else if(i>id){
      throw runtime_error("obj  not created\n");
    }
    else if(i==id){
        inst[id]=new demo();
        id++;
        return inst[id-1];
      }
      else{
        return inst[i];
      }
    }
    void disp(){
      cout<<"the id is "<<id;
    }
  };
  demo* demo::inst[]={NULL};
  int demo::id =0;
*/
demohandler* demohandler::inst=NULL;

demohandler* demohandler::getinst(){
  if (inst==NULL){
    inst=new demohandler();
  }
  return inst;
}

demo* demohandler::gethandle(int i){
  /*if (i>4){
    throw logic_error("Cannot create more than 5 instances of demo");
  }
  */

  /*if(mp.find(i)==mp.end()){
    mp.insert(make_pair(i,new demo()));
    return mp[i];
  }
  else{
    return mp[i];
  }
  */
  if(mp.find(i)!=mp.end()){
    return mp[i];
  }
  if(mp.find(i)==mp.end()&& mp.size()<5){
    mp.insert(make_pair(i,new demo()));
    return mp[i];
  }
  throw logic_error("Cannot create more than 5 instances of demo");
}
void demo::disp(){
  cout<<"disp func \n";
}
void demo::some(){
  cout<<"some func \n";
}

int main(){
  try{
  demohandler* handler;//[6];
  handler= demohandler::getinst();
  demo* obj[6];
  for(int i =5;i<16;i++){
    cout<<"creating obj "<<i<<"\n";
    obj[i]=handler->gethandle(i);
    //obj=obj->gethandle(1);
}
}
catch(logic_error &e){
  std::cerr<<"error stream"<<e.what();
}
catch(runtime_error &e){
  std::cerr<<"error stream"<<e.what();
}

}
