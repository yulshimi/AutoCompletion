#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
  int num = 99999;
  ofstream out_stream;
  out_stream.open("final.txt");
  out_stream.write((char*)&num, sizeof(num));
  return 0;
}
