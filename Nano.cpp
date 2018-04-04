#include <iostream>
//#include "util.h"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
void load_dict(vector<string>& dict, istream& words, unsigned int num_words);
int main ()
{
  ifstream in_stream;
  in_stream.open("shuffled_freq_dict.txt");
  vector<string> myVector;
  load_dict(myVector, in_stream, 10);
  for(int i=0; i < 10; ++i)
  {
    cout << myVector[i] << endl;
  }
  myVector.clear();
  in_stream.clear();
  in_stream.seekg(0, ios::beg);
  load_dict(myVector, in_stream, 10);
  for(int i=0; i < 10; ++i)
  {
    cout << myVector[i] << endl;
  }
  in_stream.close();
  long long myLong = 2.44444444444;
  int myInt = 20;
  cout << myLong/20.0 << endl;
  return 0;
}
void load_dict(vector<string>& dict, istream& words, unsigned int num_words)
{
  unsigned int freq;
  string data = "";
  string temp_word = "";
  string word = "";
  vector<string> word_string;
  unsigned int i = 0;
  unsigned int j = 0;
  for(; j < num_words; j++)
    {
      getline(words, data);
      if(words.eof()) break;
      temp_word = "";
      word = "";
      data = data + " .";
      istringstream iss(data);
      iss >> freq;
      while(1)
        {
          iss >> temp_word;
          if(temp_word == ".") break;
          if(temp_word.length() > 0) word_string.push_back(temp_word);
        }
      for(i = 0; i < word_string.size(); i++)
        {
          if(i > 0) word = word + " ";
          word = word + word_string[i];
        }
      dict.push_back(word);
      word_string.clear();
    }
}

