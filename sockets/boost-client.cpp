#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <sstream>

//using namespace std;
using namespace boost::asio;


void senddata(ip::tcp::socket &csocket,const std::string &data){
  write(csocket,buffer(data+"\n"));
}
std::string getdata(ip::tcp::socket &socket){
  streambuf buf;
  read_until(socket,buf,"\n");
  boost::asio::streambuf::const_buffers_type bufs = buf.data();
  std::string str(boost::asio::buffers_begin(bufs),
                boost::asio::buffers_begin(bufs) + buf.size());
  return str;
}

int main(){
  io_service io;
  ip::tcp::socket csocket(io);
  csocket.connect(ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"),9999));
  std::string data="namaste from client1";
  std::cout<<"c0 ";
  senddata(csocket,data);
  std::cout<<"c1 ";
  while(1){
    std::cout<<"c2 ";
    data=getdata(csocket);
    std::cout<<"c3 ";
    std::cout<<data<<"\n";
    if(data=="exit"){
      std::cout<<"client rx exit";
      break;
    }
    std::cout<<"c4 ";
    std::string reply;
    std::cin>>reply;
    std::cout<<"c5 ";
    senddata(csocket,reply);
    std::cout<<"c6 ";
  }
}
