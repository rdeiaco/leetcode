#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    int index = 0;
    bool leading = true;
    /* Remove multiple whitespace between words.
     * Also remove trailing and leading whitespace.
     */
    for (int i = 0; i < s.size(); i++) {
      if (leading && s[i] == ' ') {
        continue;
      }
      if (leading && s[i] != ' ') {
        leading = false;
      }
      if (i > 0 && s[i] == ' ' && s[i-1] == ' ') {
        continue;
      }
      s[index] = s[i];
      index++;
    }

    for (int i = s.size()-1; i >= index; i--) {
      s.pop_back();
    }
    
    for (int i = s.size()-1; i >= 0; i--) {
      if (s[i] == ' ') {
        s.pop_back();
      }  
      else {
        break;
      }
    } 

    /* Reverse the entire string.
     */
    for (int i = 0; i < s.size() / 2; i++) {
      char temp = s[i];
      s[i] = s[s.size() - 1 - i];
      s[s.size() - 1 - i] = temp;
    }

    /* Reverse each word in the string.
     */
    int j = 0;
    int k = 0;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ' && i != s.size() - 1) {
        continue;
      }

      if (s[i] == ' ') {
        k = i;  
      } 
      else if (i == s.size()-1) {
        k = i + 1;
      }

      for (int l = j; l < j + (k - j) / 2; l++) {
        char temp = s[l];
        s[l] = s[k - 1 - (l - j)];
        s[k - 1 - (l - j)] = temp;
      }
      j = k + 1;
    }


  }
};

int main(void) {
  Solution sol;
  string s = "    abc   ds  d rf  f fjk  ";
  sol.reverseWords(s);
  cout << s << "\n" << s.size() << "\n";
}

