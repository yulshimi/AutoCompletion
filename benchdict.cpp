//Name: Phillip Jo, San Kang
//Date: 02/08/2017/Wed
//Overview: This program is to figure out the average running time for three differnet type of data structures in the worst case
//Assignment#: PA2

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "DictionaryBST.h"
#include "DictionaryTrie.h"
#include "DictionaryHashtable.h"
#include "util.h"
using namespace std;
void load_dict(vector<string>& dict, istream& words, unsigned int num_words);
int main (int argc, char* argv[])
{
  if(argc != 5)
  {
    return 0;
  } 
  int min_size;
  int step_size;
  int num_iterations;
  long long theSum = 0.0;
  long long thePart = 0.0;
  Timer myTimer;
  istringstream buffer1(argv[1]);
  istringstream buffer2(argv[2]);
  istringstream buffer3(argv[3]);

  buffer1 >> min_size;
  buffer2 >> step_size;
  buffer3 >> num_iterations;

  ifstream in_stream;
  in_stream.open(argv[4]);
  if(in_stream.fail())
  {
    exit(1);
  }
  Utils myUtil;
  vector<string> myVector;
  cout << "DictionaryBST" << endl;
  for(int i=0; i < num_iterations; ++i)
  {
    theSum = 0.0;
    in_stream.clear();
    in_stream.seekg(0, ios::beg);
    DictionaryBST* BSTPtr = new DictionaryBST();
    int load_size = min_size + i*step_size;
    myUtil.load_dict(*BSTPtr, in_stream, load_size);
    load_dict(myVector, in_stream, 100);
    for(int k=0; k < 10; ++k)
    {
      for(int j=0; j < 100; ++j)
      {
        myTimer.begin_timer();
        BSTPtr->find(myVector[j]);
        thePart = myTimer.end_timer();
        theSum = theSum + thePart;    
      }
    }
    cout << min_size + i*step_size << "\t" << theSum/1000.0 << endl;
    delete BSTPtr;
    myVector.clear();  
  }
  cout << "DictionaryHashtable" << endl;
  for(int i=0; i < num_iterations; ++i)
  {
    theSum = 0.0;
    in_stream.clear();
    in_stream.seekg(0, ios::beg);
    DictionaryHashtable* hashPtr = new DictionaryHashtable();
    int load_size = min_size + i*step_size;
    myUtil.load_dict(*hashPtr, in_stream, load_size);
    load_dict(myVector, in_stream, 100);
    for(int k=0; k < 10; ++k)
    {
      for(int j=0; j < 100; ++j)
      {
        myTimer.begin_timer();
        hashPtr->find(myVector[j]);
        thePart = myTimer.end_timer();
        theSum = theSum + thePart;
      }
    }
    cout << min_size + i*step_size << "\t" << theSum/1000.0 << endl;
    delete hashPtr;
    myVector.clear();
  }
  cout << "DictionaryTrie" << endl;
  for(int i=0; i < num_iterations; ++i)
  {
    theSum = 0.0;
    in_stream.clear();
    in_stream.seekg(0, ios::beg);
    DictionaryTrie* triePtr = new DictionaryTrie();
    int load_size = min_size + i*step_size;
    myUtil.load_dict(*triePtr, in_stream, load_size);
    load_dict(myVector, in_stream, 100);
    for(int k=0; k < 10; ++k)
    {
      for(int j=0; j < 100; ++j)
      {
        myTimer.begin_timer();
        triePtr->find(myVector[j]);
        thePart = myTimer.end_timer();
        theSum = theSum + thePart;
      }
    }
    cout << min_size + i*step_size << "\t" << theSum/1000.0 << endl;
    delete triePtr;
    myVector.clear();
  }

  return 0;
}
//This function loads num_words words from the dictionary to a vector
//It is the modified version of given load_dict function
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

