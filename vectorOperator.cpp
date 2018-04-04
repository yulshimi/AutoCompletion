#include <iostream>
#include <vector>
using namespace std;
vector<int> operator+(vector<int>&  theFirst, vector<int>& theSecond);
int main ()
{
  vector<int> myVector;
  vector<int> herVector;
  for(int i=0; i < 20; ++i)
  {
    myVector.push_back(i);
  }
  for(int i=21; i < 60; ++i)
  {
    herVector.push_back(i);
  }
  vector<int> neoVector;
  neoVector = myVector + herVector;
  for(int i=0; i < neoVector.size(); ++i)
  {
    cout << neoVector[i];
  }
  cout << endl;
  return 0;
}

vector<int> operator+(vector<int>& theFirst, vector<int>& theSecond)
{
  vector<int> newVector;
  newVector = theFirst;
  for(int i=0; i < theSecond.size(); ++i)
  {
     newVector.push_back(theSecond[i]);
  }
  return newVector;
}

