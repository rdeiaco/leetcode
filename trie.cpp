#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
  TrieNode(char val) : val(val), next{0} {
  }
    
  char val;
  TrieNode *next[27];
};

class Trie {
public:
  /** Initialize your data structure here. */
  Trie() {
    this->root = new TrieNode(static_cast<char>(26));
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode *temp = this->root;
    for (const char c : word) {
      if (temp->next[static_cast<int>(c - 'a')] == nullptr) {
        temp->next[static_cast<int>(c - 'a')] = new TrieNode(c);
      }
      temp = temp->next[static_cast<int>(c - 'a')];
    }
    if (temp->next[26] == nullptr) {
      temp->next[26] = new TrieNode(static_cast<char>(26));
    }

  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode *temp = this->root;
    for (char c : word) {
      temp = temp->next[static_cast<int>(c - 'a')];
      if (temp == nullptr) {
        return false;
      }
    }
    if (temp->next[26] != nullptr) {
      return true;
    }
    else {
      return false;
    }

  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    TrieNode *temp = this->root;
    for (char c : prefix) {
      temp = temp->next[static_cast<int>(c - 'a')];
      if (temp == nullptr) {
        return false;
      }
    }
    return true;

  }

  TrieNode *root;
};

int main(void) {
  Trie trie;

  trie.insert("apple");
  cout << (trie.search("apple") == true) << endl;
  cout << (trie.search("app") == false) << endl;
  cout << (trie.startsWith("app") == true) << endl;
  trie.insert("app");
  cout << (trie.search("app") == true) << endl;
  trie.insert("application");
  cout << (trie.search("app") == true) << endl;
  cout << (trie.search("apple") == true) << endl;
  cout << (trie.search("applicable") == false) << endl;
  cout << (trie.search("application") == true) << endl;
  
}
