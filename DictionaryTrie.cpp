//Name: Phillip Jo, San Kang
//Date: 02/08/2017/Wed
//Overview: This program is the implementation of "DictionaryTrie.h"
//Assignment#: PA2

#include <cctype>
#include "util.h"
#include "DictionaryTrie.h"
#include <iostream>
using namespace std;
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
    if(word[0] == ' ' || word[word.length()-1] == ' ')
    {
      word = ignore_space(word);
    }
    if(word.length() == 0) //empty string is not allowed
    {
      return false;
    }
    for(unsigned int i=0; i < word.length(); ++i)
    {
      int ascii_val = (int)word[i];
      if((ascii_val < 97 || ascii_val > 122) && ascii_val != 32)
      {
        if(ascii_val >= 65 && ascii_val <= 90)
        {
          word[i] = tolower(word[i]);
        }
        else
        {
          return false;
        }
      }
    }
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
  if(word[0] == ' ' || word[word.length()-1] == ' ')
  {
    word = ignore_space(word);
  }
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

//This function is to return Node* which points to Node after prefix
//If prefix is invalid, it returns nullptr
Node* DictionaryTrie::getNodePtr(std::string prefix) const
{
  Node* nodePtr = root;
  if(prefix.length() == 0)
  {
    return nullptr;
  }
  for(unsigned int i=0; i < prefix.length(); ++i)
  {
    int index = 0;
    if(prefix[i] != ' ')
    {
      index = (int)(prefix[i]) - (int)'a';
    }
    else
    {
      index = ARRAY_SIZE - 1;
    }
    if(nodePtr->nodePtrArray[index] != nullptr)
    {
      nodePtr = nodePtr->nodePtrArray[index];
    }
    else
    {
      return nullptr;
    }
  }
  return nodePtr;
}
//This function is to cut off all space characters at the beginning and at the end
std::string DictionaryTrie::ignore_space(std::string prefix) const
{
  int cut_point_front = 0;
  int cut_point_back = 0;
  string new_prefix = "";
  if(prefix[0] == ' ')
  {
    for(unsigned int i=0; i < prefix.length(); ++i)
    {
      if(prefix[i] != ' ')
      {
        cut_point_front = i;
        break;
      }
    }
    if(cut_point_front == 0)
    {
      return new_prefix;
    }
  }
  if(prefix[prefix.length()-1] == ' ')
  {
    for(int i=prefix.length()-1; i >= 0; --i)
    {
      if(prefix[i] != ' ')
      {
        cut_point_back = i;
        break;
      }
    }
  }
  if(cut_point_back == 0)
  {
    if(prefix[prefix.length()-1] != ' ')
    {
      cut_point_back = prefix.length()-1;
    }
  }
  for(int i = cut_point_front; i <= cut_point_back; ++i)
  {
    new_prefix = new_prefix + prefix[i];
  }
  return new_prefix; 
}

bool DictionaryTrie::isItValidPrefix(std::string& prefix, unsigned int num_completions, Node*& nodePtr) const
{
  if(num_completions == 0)
  { 
    return false;
  }
  if(prefix.length() == 0)
  {
    std::cout << "Invalid Input. Please retry with correct input \n";
    return false; 
  }
  if(prefix[0] == ' ' || prefix[prefix.length()-1] == ' ')
  { 
    prefix = ignore_space(prefix);
  } 
  for(unsigned int i=0; i < prefix.length(); ++i)
  { 
    int ascii_val = (int)prefix[i]; 
    if((ascii_val < 97 || ascii_val > 122) && ascii_val != 32)
    { 
      if(ascii_val <= 90 && ascii_val >= 65)
      { 
        prefix[i] = tolower(prefix[i]);
      }
      else
      { 
        std::cout << "Invalid Input. Please retry with correct input \n";
        return false;
      }
    }
  }
  nodePtr = getNodePtr(prefix);
  if(nodePtr == nullptr)
  {
    std::cout << "Invalid Input. Please retry with correct input \n";
    return false;
  }

  return true;
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
  Node* nodePtr;
  std::vector<std::string> words;
  if(!isItValidPrefix(prefix, num_completions, nodePtr))
  {
    return words;
  }
/************************************************************************
This code is what used to be here and removed for improvement 
   if(num_completions == 0)
  {
    return words;
  }
  if(prefix[0] == ' ' || prefix[prefix.length()-1] == ' ')
  {
    prefix = ignore_space(prefix);
  } 
  if(prefix.length() == 0)
  {
    std::cout << "Invalid Input. Please retry with correct input \n";
    return words;  //return a null vector
  }
  for(unsigned int i=0; i < prefix.length(); ++i)
  {
    int ascii_val = (int)prefix[i];
    if((ascii_val < 97 || ascii_val > 122) && ascii_val != 32)
    {
      if(ascii_val <= 90 && ascii_val >= 65)
      {
        prefix[i] = tolower(prefix[i]);
      }
      else
      {
        std::cout << "Invalid Input. Please retry with correct input \n";
      }
    }
  }
************************************************************************/
  BST tempBST;
  predictHelper(tempBST, nodePtr, prefix);
  if(num_completions <= tempBST.getSize())
  {
    words = tempBST.theHighestFreq(words, num_completions);
    return words; 
  } 
  else
  {
    words = tempBST.theHighestFreq(words, tempBST.getSize());
    unsigned int completionDone = tempBST.getSize();
    std::string currPrefix = "";
    std::string prevPrefix = prefix;
    while(completionDone < num_completions)
    {
      tempBST.deleteAll(tempBST.getRoot());
      tempBST.setSize(0);
      tempBST.setTreeNode(nullptr);
      for(unsigned int i=0; i < prevPrefix.length() - 1; ++i)
      {
        currPrefix = currPrefix + prevPrefix[i];
      }
      nodePtr = getNodePtr(currPrefix);
      if(nodePtr == nullptr)
      {
        return words;
      }
      char avoidChar = prevPrefix[prevPrefix.length() - 1];
      neoPredictHelper(tempBST, nodePtr, currPrefix, avoidChar);
      std::vector<std::string> neoVector;
      if((num_completions - completionDone) <= tempBST.getSize())
      {
        neoVector = tempBST.theHighestFreq(neoVector, num_completions - completionDone);
        words = words + neoVector;
        return words;  
      }
      else
      {
        neoVector = tempBST.theHighestFreq(neoVector, tempBST.getSize());
        words = words + neoVector;
        completionDone = completionDone + tempBST.getSize();
        prevPrefix = currPrefix;
        currPrefix = "";
        if(prevPrefix.length() == 1)
        {
          return words;
        }
      }
    }      
  }
  return words;
}
/**********************************************************************
This function is to build a BST to be prepared for sorting
***********************************************************************/
void DictionaryTrie::predictHelper(BST& myBST, Node* currentPtr, std::string word) const
{
  if(currentPtr->isItWord == true)
  {
    myBST.insert(word, currentPtr->frequency); 
  }  
  
  for(int i=0; i < ARRAY_SIZE; ++i)
  {
    if(currentPtr->nodePtrArray[i] != nullptr)
    {
      std::string newWord;
      if(i != (ARRAY_SIZE - 1))
      {
        newWord = word + (char)(i + ASCII); 
      }
      else
      {
        newWord = word + ' ';
      }
      predictHelper(myBST, currentPtr->nodePtrArray[i], newWord);
    }    
  }
}
//This function is the same as predictHelper
//It skips the index of avoidChar
void DictionaryTrie::neoPredictHelper(BST& myBST, Node* currentPtr, std::string word, char avoidChar) const
{
  if(currentPtr->isItWord == true)
  {
    myBST.insert(word, currentPtr->frequency);
  }
  for(int i=0; i < ARRAY_SIZE; ++i)
  {
    if((i + ASCII) != (int)avoidChar)
    {
      if(currentPtr->nodePtrArray[i] != nullptr)
      {
        std::string newWord;
        if(i != (ARRAY_SIZE - 1))
        {
          newWord = word + (char)(i + ASCII);
        }
        else
        {
          newWord = word + ' ';
        }
        predictHelper(myBST, currentPtr->nodePtrArray[i], newWord);
      }
    }  
  }
}
/* Destructor */
DictionaryTrie::~DictionaryTrie()
{
  deleteAll(root);
}

treeNode::treeNode()
{
  treeWord = "";
  treeFreq = 0;
  leftChild = nullptr;
  rightChild = nullptr;
  parent = nullptr;
}
/***********************************************************
The code below is the implementation of BST
We have decided to use BST because all elements are
automatically sorted when they are inserted, so it is easy to
locate nodes which have the highest frequencies.
Since it is only for helping Trie,
some unneccessary functions or variables are omitted.
***********************************************************/
treeNode::treeNode(std::string myString, unsigned int myFreq)
{
  treeWord = myString;
  treeFreq = myFreq;
  leftChild = nullptr;
  rightChild = nullptr;
  parent = nullptr;
}
BST::BST()
{
  root = nullptr;
  size = 0;
}

unsigned int BST::getSize() const
{
  return size;
}

bool BST::isEmpty() const
{
  return (size == 0);
}

treeNode* BST::getRoot() const
{
  return root;
}

bool BST::insert(std::string myWord, unsigned int myFreq)
{
  if(isEmpty() == true)
  {
    treeNode* newNodePtr = new treeNode(myWord, myFreq);
    root = newNodePtr;
    ++size;
    return true;  
  }
  
  treeNode* insertPtr = root;

  while(((insertPtr->treeFreq <= myFreq) && (insertPtr->rightChild != nullptr)) || ((myFreq < insertPtr->treeFreq) && (insertPtr->leftChild != nullptr)))
  {
    if(insertPtr->treeFreq <= myFreq)
    {
      insertPtr = insertPtr->rightChild;
    }
    else
    {
      insertPtr = insertPtr->leftChild;
    }
  }

  treeNode* newNodePtr = new treeNode(myWord, myFreq);

  if(insertPtr->treeFreq <= myFreq)
  {
    insertPtr->rightChild = newNodePtr;
    newNodePtr->parent = insertPtr;
    ++size;
    return true;
  }
  else
  {
    insertPtr->leftChild = newNodePtr;
    newNodePtr->parent = insertPtr;
    ++size;
    return true;
  }

  return false;
}

void BST::deleteAll(treeNode* deletePtr)
{
  if(deletePtr != nullptr)
  {
    deleteAll(deletePtr->leftChild);
    deleteAll(deletePtr->rightChild);
    delete deletePtr;
  }  
}

void BST::setSize(int newSize)
{
  size = newSize;
}
/* It returns a vector containg the highest numOfCompletion words.
 * It assumes that numOfCompletion is a valid number
 * Invalid number is handled before this function
 */  
std::vector<std::string> BST::theHighestFreq(std::vector<std::string>&  myVector, unsigned int numOfCompletion)
{
  treeNode* searchPtr = root;

  while(searchPtr->rightChild != nullptr)
  {
    searchPtr = searchPtr->rightChild;
  }
  
  myVector.push_back(searchPtr->treeWord);
  --numOfCompletion;
  
  while(0 < numOfCompletion)
  {
    if(searchPtr->leftChild != nullptr)
    {
      searchPtr = searchPtr->leftChild;
      while(searchPtr->rightChild != nullptr)
      {
        searchPtr = searchPtr->rightChild;
      } 
    }
    else
    {
      unsigned int currFreq = searchPtr->treeFreq;
      while(searchPtr->parent != nullptr)
      {
        searchPtr = searchPtr->parent;
        if(searchPtr->treeFreq <= currFreq)
        {
          break;
        }  
      }
    }  
    myVector.push_back(searchPtr->treeWord);
    --numOfCompletion;
  }
  
  return myVector;
}

void BST::setTreeNode(treeNode* setPtr)
{
  root = setPtr;
}

BST::~BST()
{
  deleteAll(root);
}
//This function is to combine two vectors
std::vector<std::string> operator+(std::vector<std::string>& theFirst, std::vector<std::string>& theSecond)
{
  std::vector<std::string> neoVector;
  neoVector = theFirst;
  for(unsigned int i=0; i < theSecond.size(); ++i)
  {
    neoVector.push_back(theSecond[i]);
  }  
  return neoVector;
}






































