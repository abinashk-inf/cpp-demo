#include<iostream>
#include<boost/asio.hpp>

//using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

void senddata(tcp::socket &csocket,const std::string &data){
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

int main(int argc, char* argv[])
{
    io_service io;
    // Listening for any new incomming connection
    // at port 9999 with IPv4 protocol
    tcp::acceptor acceptor_server(io, tcp::endpoint(tcp::v4(), 9999));
    // Creating socket object
    ip::tcp::socket ssocket(io);
    // waiting for connection
    acceptor_server.accept(ssocket);
    //std::string data="namaste from server";
    std::string data="namaste from server";
    std::cout<<"s0 ";
    senddata(ssocket,data);
    std::cout<<"s1 ";
    while(1){
      std::cout<<"s2 ";
      data=getdata(ssocket);
      std::cout<<"s3 ";
      std::cout<<data<<"\n";
      if(data=="exit"){
        std::cout<<"server rx exit";
        break;
      }
      std::cout<<"s4 ";
      std::string reply;
      std::cin>>reply;
      std::cout<<"s5 ";
      senddata(ssocket,reply);
      std::cout<<"s6 ";

    }
    return 0;

}
