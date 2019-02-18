#include <vector>
#include <deque>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
      return vector<string>();
    }

    const vector<string> char_lookup = {"abc", "def", "ghi", "jkl", 
      "mno", "pqrs", "tuv", "wxyz"};
    deque<string> string_queue;
    string_queue.push_back(""); 

    for (char d : digits) {
      int queue_length = string_queue.size();
      for (int i = 0; i < queue_length; i++) {
        string temp = string_queue.front();
        string_queue.pop_front();

        int lookup_index = static_cast<int>(d - '2');
        for (char c : char_lookup[lookup_index]) {
          temp.push_back(c);
          string_queue.push_back(temp);
          temp.pop_back();
        }
      }
    }

    vector<string> retval = vector<string>({string_queue.begin(), string_queue.end()});
    return retval;

  }
};

int main(void) {
  Solution sol;
  
  vector<string> result = sol.letterCombinations("2");
  for (string s : result) {
    cout << s << "\n";
  }
  cout << "\n";

  result = sol.letterCombinations("");
  cout << result.size() << "\n";

}
