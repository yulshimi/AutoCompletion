//Name: Phillip Jo
//Date: 02/08/2017/Wed
//Overview: This is the implementation of DictionaryHashtable.h
//Assignment#: PA2
#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
  std::pair<std::unordered_set<std::string>::iterator, bool> pairReturn;
  pairReturn = myTable.insert(word);
  return pairReturn.second;  
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
  return (myTable.find(word) != myTable.end());
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}
