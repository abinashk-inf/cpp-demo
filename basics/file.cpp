#include <iostream>
//#include <map>
//#include<vector>
#include<fstream>
using namespace std;

void write(){
  ofstream fp;
  fp.open("demo.txt");
  fp<<"kya haal chaal h bhai?\n";
  fp<<"bro wassup?\n";
  fp.close();
}
void read(){
  ifstream fp;
  fp.open("demo.txt");
  string s;
  while (getline(fp,s)) {
    cout<<s;
  }
  fp.close();
}
int main(){
  write();
  read();

}
