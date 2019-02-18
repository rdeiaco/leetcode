#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.size() == 0) {
      return "";
    }

    bool is_palindrome[s.size()][s.size()] = {0};

    int max_i = 0;
    int max_j = 0;
    int max_len = 0;

    for (int j = 0; j < s.size(); j++) {
      for (int i = 0; i <= j; i++) {
        if (j == i) {
          is_palindrome[i][j] = true;
          if (j - i + 1 >= max_len) {
            max_len = j - i + 1;
            max_i = i;
            max_j = j;
          }
        }
        else if (j - i == 1) {
          if (s[i] == s[j]) {
            is_palindrome[i][j] = true;
            if (j - i + 1 >= max_len) {
              max_len = j - i + 1;
              max_i = i;
              max_j = j;
            }
          }
        }
        else {
          is_palindrome[i][j] = is_palindrome[i+1][j-1] && (s[i] == s[j]);
          if (is_palindrome[i][j]) {
            if (j - i + 1 >= max_len) {
              max_len = j - i + 1;
              max_i = i;
              max_j = j;
            }
          }
        }
      }
    }

    return s.substr(max_i, max_len);

  }

};

int main(void) {
  Solution sol;
  cout << sol.longestPalindrome("cbbd") << "\n";
  cout << sol.longestPalindrome("babad") << "\n";
  cout << sol.longestPalindrome("jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx") << "\n";

}
