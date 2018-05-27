class demo{
public:
  void disp();
  void some();
};
class demohandler{
  static demohandler* inst;
  std::map<int, demo*>mp;
  demohandler(){}
public:
  static demohandler* getinst();
  demo* gethandle(int);
};
