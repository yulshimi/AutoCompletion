//Name: Phillip Jo, San Kang
//Date: 02/08/2017/WED
//Overview: This program is to compare one hash function with another hash function
//Assignment#: PA2

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#define TABLE_SIZE 2
using namespace std;
int firstHash(string word, int tableSize);
int secondHash(string word, int tableSize);
int theSum(int n);
void load_dict(vector<string>& dict, istream& words, unsigned int num_words);

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    return 0;
  }
  int num_words = 0;
  istringstream buffer1(argv[2]);
  buffer1 >> num_words;

  int sizeOfTable = TABLE_SIZE*num_words;
  int hitArray_one[num_words] = {};
  int hitArray_two[num_words] = {};

  vector<string> vecArray_one[sizeOfTable];
  vector<string> vecArray_two[sizeOfTable];
  vector<string> wordVector;

  ifstream in_stream;
  in_stream.open(argv[1]);
  if(in_stream.fail())
  {
    exit(1);
  }
  load_dict(wordVector, in_stream, num_words);
  
  for(int i=0; i < num_words; ++i) // insertion
  {
    int index = 0;
    index = firstHash(wordVector[i], sizeOfTable);
    vecArray_one[index].push_back(wordVector[i]);
    index = secondHash(wordVector[i], sizeOfTable);
    vecArray_two[index].push_back(wordVector[i]); 
  }
  
  for(int i=0; i < sizeOfTable; ++i)
  {
    int index = 0;
    index = vecArray_one[i].size();
    ++hitArray_one[index];
    index = vecArray_two[i].size();
    ++hitArray_two[index];
  }  
  cout << "Printing the statistics for hashFunction1 with hash table size " << sizeOfTable << endl;
  cout << "#hits\t#slots receiving the #hits" << endl;
  for(int i=0; i < num_words; ++i)
  {
    if(0 < hitArray_one[i])
    {
      cout << i << "\t" << hitArray_one[i] << endl;
    }
  }

  int worst_steps = 0;
  int total_steps = 0;
  int partial_steps = 0;
  double average = 0.0;

  for(int i=0; i < sizeOfTable; ++i)
  {
    partial_steps = vecArray_one[i].size();
    if(worst_steps < partial_steps)
    {
      worst_steps = partial_steps;
    }
    partial_steps = theSum(partial_steps);
    total_steps = total_steps + partial_steps;
  }
  
  average = total_steps / (num_words*1.0);
  cout << "The average number of steps for a successful search for hash function 1 would be " << average << endl;
  cout << "The worst case steps that would be needed to find a word is " << worst_steps << endl;
  cout << endl;
  cout << "Printing the statistics for hashFunction2 with hash table size " << sizeOfTable << endl;
  cout << "#hits\t#slots receiving the #hits" << endl;
  for(int i=0; i < num_words; ++i)
  {
    if(0 < hitArray_two[i])
    {
      cout << i << "\t" << hitArray_two[i] << endl;
    }
  }

  worst_steps = 0;
  total_steps = 0;
  partial_steps = 0;
  average = 0.0;

  for(int i=0; i < sizeOfTable; ++i)
  {
    partial_steps = vecArray_two[i].size();
    if(worst_steps < partial_steps)
    {
      worst_steps = partial_steps;
    }
    partial_steps = theSum(partial_steps);
    total_steps = total_steps + partial_steps;
  }
  
  average = total_steps / (num_words*1.0);
  cout << "The average number of steps for a successful search for hash function 2 would be " << average << endl;
  cout << "The worst case steps that would be needed to find a word is " << worst_steps << endl; 
  return 0;
}
//The source of two hash functions: "http://stackoverflow.com/questions/8317508/hash-function-for-a-string"
int firstHash(string word, int tableSize)
{
  int sum = 0;
  for(unsigned int i=0; i < word.length(); ++i)
  {
    sum = sum + (int)word[i];
  }
  return sum%tableSize;
}

int secondHash(string word, int tableSize)
{
  int seed = 131;
  unsigned long hash = 0;
  for(unsigned int i=0; i < word.length(); ++i)
  {
    hash = (hash*seed) + word[i];
  }
  return hash%tableSize;
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

int theSum(int n)
{
  if(n <= 0)
  {
    return 0;
  }
  return n + theSum(n-1);  
}

  
