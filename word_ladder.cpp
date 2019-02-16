#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
      unordered_map<string, int> count_map;
      unordered_map<string, bool> open;
      unordered_map<string, bool> closed;
      queue<string> search_queue;

      count_map[beginWord] = 1;
      open[beginWord] = true;
      search_queue.push(beginWord);

      while (!search_queue.empty()) {
        string u = search_queue.front();
        search_queue.pop();
        open[u] = false;
        closed[u] = true;

        for (string v : wordList) {
          if ((!closed[v]) && (validStep(u, v))) {
            if (count_map.find(v) != count_map.end()) {
              count_map[v] = min(count_map[v], count_map[u] + 1);
            }
            else {
              count_map[v] = count_map[u] + 1;
            }

            if ((!open[v]) && (!closed[v])) {
              open[v] = true;
              search_queue.push(v);
            }
          }
        }
      }

      if (count_map.find(endWord) != count_map.end()) {
        return count_map[endWord];
      }
      else {
        return 0;
      }
    }

    bool validStep(string u, string v) {
      int error_count = 0;
      for (string::size_type i = 0; i < u.size(); i++) {
        if (u[i] != v[i]) {
          error_count += 1;
          if (error_count > 1) {
            return false;
          }
        } 
      }

      if (error_count == 1) {
        return true;
      }
      else {
        return false;
      }
    }

};

int main(void) {
  Solution sol;
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
  cout << sol.ladderLength("hit", "cog", wordList) << "\n";
}
