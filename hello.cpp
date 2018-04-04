#include <iostream>
#include <string>
using namespace std;
void stringConvert(string& prefix)
{
  prefix = "Phillip Jo";
}
void pointer(int*& intPtr)
{
  int myInt = 1000;
  intPtr = &myInt;
}
int main ()
{
  string myString = "";
  stringConvert(myString);
  cout << myString << endl;
  int* ptr;
  int t = 9999;
  ptr = &t;
  cout << ptr << endl;
  pointer(ptr);
  cout << ptr << endl;
  return 0;
}
