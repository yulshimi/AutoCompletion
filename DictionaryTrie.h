/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H
#define ARRAY_SIZE 27
#define ASCII 97
#include <vector>
#include <string>
class treeNode
{
public:
  treeNode();
  treeNode(std::string myString, unsigned int myFreq);
  std::string treeWord;
  unsigned int treeFreq;
  treeNode* leftChild;
  treeNode* rightChild;
  treeNode* parent;
};
class BST
{
public:
  BST();
  ~BST();
  void setSize(int newSize);
  unsigned int getSize() const;
  bool isEmpty() const;
  treeNode* getRoot() const;
  bool insert(std::string myWord, unsigned int myFreq);
  void deleteAll(treeNode* deletePtr);
  std::vector<std::string> theHighestFreq(std::vector<std::string>& myVector, unsigned int numOfCompletion); 
private:
  treeNode* root;
  unsigned int size;
};

class Node
{
public:
  Node();
  Node* nodePtrArray[ARRAY_SIZE];
  bool isItWord;
  unsigned int frequency;
};
/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */
class DictionaryTrie
{
public:

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

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
  std::vector<std::string> predictCompletions(std::string prefix, unsigned int num_completions);
  /* Destructor */
  ~DictionaryTrie();

private:
  Node* root;
  void deleteAll(Node* deletePtr);
  void predictHelper(BST& myBST, Node* currentPtr, std::string word);
  void neoPredictHelper(BST& myBST, Node* currentPtr, std::string word, char avoidChar);
  Node* getNodePtr(std::string prefix);
  // Add your own data members and methods here
};
std::vector<std::string> operator+(std::vector<std::string>& theFirst, std::vector<std::string>& theSecond);

#endif // DICTIONARY_TRIE_H
