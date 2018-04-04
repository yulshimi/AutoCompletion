#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main ()
{
  string a = "hahahahah";
  string b = "I am I am";
  string neo;
  neo = a + (char)97;
  cout << neo << endl;
  neo = a + (char)97 + (char)97 + ' ' + b;
  cout << neo << endl;
  return 0;
}
