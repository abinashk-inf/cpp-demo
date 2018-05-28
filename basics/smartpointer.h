/*unique ptr */
template <class T>
class smart_ptr{
  T *ptr;
  // a single owner allowed
  /*better implementation than delete
  They're basically different things.
  private tells you that only members of the class can call that method or access that variable (or friends of course).
  In this case, it's legal for a static method of that class (or any other member) to call a private constructor of a class. This doesn't hold for deleted constructors.
  */
  smart_ptr(const smart_ptr&)=delete;
  smart_ptr operator=(const smart_ptr&)=delete;
public:
  explicit smart_ptr(T *_ptr):ptr(_ptr){std::cout << "ctor smart ptr" << '\n';}
  T* operator->();
  T& operator*();
  ~smart_ptr(){std::cout << "dtor smart_ptr" << '\n'; delete ptr;}
};

template<class T>
T* smart_ptr<T>::operator->(){
  return ptr;
}

template<class T>
T& smart_ptr<T>::operator*(){
  return *ptr;
}

class demo{
  int p;
public:
  demo();
  demo(int);
  void show();
  void set(int);
};
