#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    vector<bool> is_palindrome_lut(s.size() * s.size());
    vector<pair<int, int>> max_pair_lut(s.size() * s.size());
    vector<bool> found_lut(s.size() * s.size());
    pair<int, int> max_pair = maxPalindrome(s, 0, s.size(), is_palindrome_lut, max_pair_lut, found_lut);

    return s.substr(max_pair.first, max_pair.second-max_pair.first);

  }

  pair<int, int> maxPalindrome(string s, int start, int end, 
    vector<bool> &is_palindrome_lut, 
    vector<pair<int, int>> &max_pair_lut,
    vector<bool> &found_lut) {

    if (end - start < 2) {
      return pair<int, int>(start, end);
    }

    int search_val = start * s.size() + end;
    if (found_lut[search_val]) {
      return max_pair_lut[search_val];
    }

    if (isPalindrome(s, start, end, is_palindrome_lut, found_lut)) {
      pair<int, int> ret_pair(start, end);
      max_pair_lut[search_val] = ret_pair;
      return ret_pair;
    }

    pair<int, int> pair1 = maxPalindrome(s, start + 1, end - 1, is_palindrome_lut, max_pair_lut, found_lut);
    pair<int, int> pair2 = maxPalindrome(s, start, end - 1, is_palindrome_lut, max_pair_lut, found_lut);
    pair<int, int> pair3 = maxPalindrome(s, start + 1, end, is_palindrome_lut, max_pair_lut, found_lut);
    int length1 = pair1.second - pair1.first;
    int length2 = pair2.second - pair2.first;
    int length3 = pair3.second - pair3.first;

    if ((length1 > length2) && (length1 > length3)) {
      max_pair_lut[search_val] = pair1;
      return pair1;
    }
    else if (length2 > length3) {
      max_pair_lut[search_val] = pair2;
      return pair2;
    }
    else {
      max_pair_lut[search_val] = pair3;
      return pair3;
    }

  }

  bool isPalindrome(string s, int start, int end, 
    vector<bool> &is_palindrome_lut, vector<bool> &found_lut) {
    if (end - start < 2) {
      return true;
    }

    int search_val = start * s.size() + end;
    if (found_lut[search_val]) {
      return is_palindrome_lut[search_val];
    }
    
    if (s[start] == s[end-1]) {
      if (isPalindrome(s, start + 1, end - 1, is_palindrome_lut, found_lut)) {
        is_palindrome_lut[search_val] = true;
        found_lut[search_val] = true;
        return true;
      }
    }

    is_palindrome_lut[search_val] = false;
    found_lut[search_val] = true;
    return false;

  }
  

};

int main(void) {
  Solution sol;
  cout << sol.longestPalindrome("babad") << "\n";
  cout << sol.longestPalindrome("jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx") << "\n";

}
