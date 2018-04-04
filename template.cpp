#include <iostream>
using namespace std;
template<int myInt>
class myClass
{
public:
  myClass()
  {
    m_int = myInt;
  }
  int m_int;
};

int main()
{
  myClass<10> myA;
  int a = 10;
  int& b = a;
  int* intPtr = &b;
  cout << &b << endl;
  cout << &a << endl;
  return 0;
}
