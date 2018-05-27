#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <fstream>
#include <string>
using namespace std;

std::mutex mtx;
void oddAndEven(int n, int end);
void vowelcount(string);
int main(int argc,char* argv[])
{
/****odd even numbers alternatively****/

/*
std::thread odd(oddAndEven, 1, 10);
std::thread Even(oddAndEven, 2, 10);

odd.join();
Even.join();
for (int i=0;i<argc;i++)
cout<<argv[i]<<"\n";
*/
/****Count vowel in separate files in diff thread****/
thread pool[argc-1];
for(int i=1;i<argc;i++){
  pool[i-1]=thread(vowelcount,argv[i]);
}
for(int i=1;i<argc;i++){
  pool[i-1].join();
}

return 0;

}

void oddAndEven(int n, int end){
  for (int x=n; x <=end;x=x+2){
    mtx.lock();
    std::cout << n << " - " << x << endl;
    mtx.unlock();
    std::this_thread::yield();
 }
}
void vowelcount(string s){
  ifstream in;
  mtx.lock();
  in.open(s);
  string line;
  int vowels=0;
  while(getline(in,line)){
    for(int i=0;i<line.size();i++){
      if(line[i]=='a'||line[i]=='e'||line[i]=='i'||line[i]=='o'||line[i]=='u')
        vowels++;
    }
  }
  std::cout << "vowels in file " << s <<"="<<vowels<<'\n';
  mtx.unlock();
  std::this_thread::yield();
}
