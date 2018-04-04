#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
void load_dict(vector<string>& dict, istream& words, unsigned int num_words);
int main ()
{
  vector<string> myVector;
  ifstream in_stream;
  in_stream.open("shuffled_freq_dict.txt");
  load_dict(myVector, in_stream, 10);
  for(unsigned int i=0; i < myVector.size(); ++i)
  {
    cout << myVector[i] << endl;
  } 
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

