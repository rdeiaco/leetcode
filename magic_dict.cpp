#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class MagicDictionary {
public:
  /** Initialize your data structure here. */
  MagicDictionary() {
    this->lut = unordered_map<string, bool>();  

  }

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    lut.clear();

    for (string s : dict) {
      for (int i = 0; i < s.size(); i++) {
        string temp = string(s); 
        for (char c = 'a'; c <= 'z'; c++) {
          if (c == s[i]) {
            continue;
          }

          temp[i] = c;
          this->lut[temp] = true;

        }
      }
    }

  }

  /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
  bool search(string word) {
    if (this->lut.find(word) != this->lut.end()) {
      return true;
    }

    return false;

  }

  unordered_map<string, bool> lut;


};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */


int main(void) {
  MagicDictionary dict;
  vector<string> words = {"hello", "hallo", "leetcode"};
  dict.buildDict(words);
  cout << dict.search("hello") << endl;
  cout << dict.search("hhllo") << endl;
  cout << dict.search("hell") << endl;
  cout << dict.search("leetcoded") << endl;
}
