#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int main ()
{
  int cut_point_front = 0;
  int cut_point_back = 0;
  string prefix = "    a a a a  ";
  string new_prefix = "";
  if(prefix[0] == ' ')
  {
    for(int i=0; i < prefix.length(); ++i)
    {
      if(prefix[i] != ' ')
      {
        cut_point_front = i;
        break;   
      }
    }
  }
  if(prefix[prefix.length()-1] == ' ')
  {
    for(int i=prefix.length()-1; i >= 0; --i)
    {
      if(prefix[i] != ' ')
      {
        cut_point_back = i;
        break;
      }
    }
  }
  if(cut_point_back == 0)
  {
    if(prefix[prefix.length()-1] != ' ')
    {
      cut_point_back = prefix.length()-1;
    }
  }
  for(int i = cut_point_front; i <= cut_point_back; ++i)
  {
    new_prefix = new_prefix + prefix[i];
  }
  cout << new_prefix.length() << endl;
  cout << prefix << endl;
  cout << new_prefix << endl;
  int myInt = new_prefix[0];
  cout << myInt << endl;
  return 0;
}
