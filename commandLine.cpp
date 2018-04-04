#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main (int argc, char* argv[])
{
  cout << argv[1] << endl;
  istringstream buffer(argv[1]);
  int value;
  buffer >> value;
  cout << value << endl;
  return 0;
}
