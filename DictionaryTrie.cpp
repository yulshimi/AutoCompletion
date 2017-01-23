#include "util.h"
#include "DictionaryTrie.h"

Node::Node()
{
  for(int i=0; i < ARRAY_SIZE; ++i)
  {
    nodePtrArray[i] = nullptr;
  }
  isItWord = false;
  frequency = 0;
}
/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie()
{
  root = new Node;
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  if(word.length() != 0)
  {
    Node* searchPtr = root;
    int index = 0;
    for(unsigned int i=0; i < word.length(); ++i)
    {
      if(word[i] == ' ')
      {
        index = ARRAY_SIZE - 1;
      }
      else
      {
        index = ((int)word[i]) - (int)'a';
      }

      if(searchPtr->nodePtrArray[index] != nullptr)
      {
        searchPtr = searchPtr->nodePtrArray[index];
      }
      else
      {
        searchPtr->nodePtrArray[index] = new Node;
        searchPtr = searchPtr->nodePtrArray[index];
      }  
    }
    if(searchPtr->isItWord != true)
    {
      searchPtr->isItWord = true;
      searchPtr->frequency = freq;
      return true;      
    }
    else
    {
      if(searchPtr->frequency < freq)
      {
        searchPtr->frequency = freq;
        return false;
      }
    }
  }
  return false;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
  Node* searchPtr = root;
  int index = 0;

  for(unsigned int i=0; i < word.length(); ++i)
  {
    if(word[i] == ' ')
    {
      index = ARRAY_SIZE - 1;
    }
    else
    {
      index = ((int)word[i]) - (int)'a';
    }

    if(searchPtr->nodePtrArray[index] != nullptr)
    {
      searchPtr = searchPtr->nodePtrArray[index];
    }
    else
    {
      return false;
    }
  }

  if(searchPtr->isItWord == true)
  {
    return true;
  }

  return false;
}

void DictionaryTrie::deleteAll(Node* deletePtr)
{
  for(int i=0; i < ARRAY_SIZE; ++i)
  {
    if(deletePtr->nodePtrArray[i] != nullptr)
    {
      deleteAll(deletePtr->nodePtrArray[i]);
    }
  }
  delete deletePtr;
}
/* Return up to num_completions of the most frequent completions
 * of the prefix, such that the completions are words in the dictionary.
 * These completions should be listed from most frequent to least.
 * If there are fewer than num_completions legal completions, this
 * function returns a vector with as many completions as possible.
 * If no completions exist, then the function returns a vector of size 0.
 * The prefix itself might be included in the returned words if the prefix
 * is a word (and is among the num_completions most frequent completions
 * of the prefix)
 */
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
  std::vector<std::string> words;
  return words;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie()
{
  deleteAll(root);
}
