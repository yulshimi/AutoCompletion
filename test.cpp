//Name: Phillip Jo
//Date: 02/08/2017/Wed
//Overview: This program is to test all three data structures heavily focused on DictionaryTrie
//Assignment#: PA2
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include <fstream>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;


int main(int argc, char** argv)
{

  //Initialize words
  vector<std::string> words;
  vector<string>::iterator wit;
  vector<string>::iterator wen;
  //initialize nonwords
  set<string> nope;
  set<string>::iterator nit;
  set<string>::iterator nen;

  //Initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;
  int t_bst, t_ht, tt;

  words.push_back("harry");
  words.push_back("sriram");
  words.push_back("cse");
  words.push_back("crucio");
  words.push_back("autocomplete");
  words.push_back("auto");
  words.push_back("autocom");
  words.push_back("harrrry");
  words.push_back("himan");
  words.push_back("thailand");
  words.push_back("agogobar");
  words.push_back("baccara");
  words.push_back("harr yyyyyy");
  words.push_back("harr yy  yyyy");
  words.push_back("h arryyy  yyy");
  words.push_back("harry yyyyy");
  words.push_back("h ar ry yyy yy");
  words.push_back(" ");
  
  
  cout << "Inserting into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 1);
      cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(t_bst && t_ht && tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
    }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 0);
      if(t_bst)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(tt)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(!t_bst && !t_ht && !tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

// This is my own test. Remove it later.  
/*You are supposed to add more test cases in this file */
  DictionaryTrie myTrie;
  myTrie.insert("AB GFG", 100 );  
  myTrie.insert("abrtrt", 200 );  
  myTrie.insert("abdewer", 300 );  
  myTrie.insert("abnmkld", 400 );  
  myTrie.insert("abvtr", 500 );  
  myTrie.insert("ab ccf", 501 );  
  myTrie.insert("abtyui", 502 );  
  myTrie.insert("abcdeq", 444 );  
  myTrie.insert("abxzxz", 999 );  
  myTrie.insert("abyuiop", 111 );  
  myTrie.insert("aatyty", 202 );  
  myTrie.insert("AARNE", 44 );  
  myTrie.insert("aalmkiu", 4 );  
  myTrie.insert("aaweqvc", 9090 );  
  myTrie.insert("aaL  ALALALA", 121212 );  
  myTrie.insert("aalc", 45678 );  
  myTrie.insert("abcMM  m mm", 442244 );  
  myTrie.insert("abcttttt",445 );  
  myTrie.insert("abcvvvvv", 990 );  
  myTrie.insert("aBcRTRTN", 465 );  
  myTrie.insert("abciuiuiu", 404 );  
  myTrie.insert("ABCDEFG", 1 );  
  myTrie.insert("aalrtrt", 2 );  
  myTrie.insert("aalvmvmvm", 3 );  
  myTrie.insert("aalPOPOPO", 42 );
  vector<string> myVector;
  myVector = myTrie.predictCompletions("A", 25);
  for(unsigned int i=0; i < myVector.size(); ++i)
  {
    cout << myVector[i] << endl;
  }

  Utils myUtil;
  ifstream in_stream;
  in_stream.open("shuffled_freq_dict.txt");
  DictionaryTrie* yourTrie = new DictionaryTrie();
  myUtil.load_dict(*yourTrie, in_stream, 5000);
  vector<string> goodVector;
  goodVector = yourTrie->predictCompletions("a", 100);
  goodVector.clear();
  goodVector = yourTrie->predictCompletions("k", 444);
  for(unsigned int i=0; i < goodVector.size(); ++i)
  {
    cout << goodVector[i] << endl;
  }
  in_stream.close();
  delete yourTrie;

  return 0;
}
