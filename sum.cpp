#include <iostream>
using namespace std;
int theSum(int n)
{
  //cout << "Hello" << endl;
  if(n <= 0)
  {
    return 0;
  }
  return (n + theSum(n-1));
}

int main ()
{
  cout << theSum(100) << endl;
  return 0;
}
