
#include <iostream>
#include <string>
#include <sstream>
#include <thread>

void loop()
{
  std::cout<<"yo nigga\n";
}
int main()
{
  std::thread th(loop);
  th.join();
  return 0;
}
