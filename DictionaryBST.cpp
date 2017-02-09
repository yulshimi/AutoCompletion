//Name: Phillip Jo
//Date: 02/08/2017/Wed
//Overview: This is the implementation of Dictionary.h
//Assignment#: PA2
#include "util.h"
#include "DictionaryBST.h"

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
  std::pair<std::set<std::string>::iterator, bool> pairReturn;
  pairReturn = mySet.insert(word);
  return pairReturn.second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
  return (mySet.find(word) != mySet.end());
}

/* Destructor */
DictionaryBST::~DictionaryBST(){}
