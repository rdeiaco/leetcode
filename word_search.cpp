#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    if (word.size() == 0) {
      return true;
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (word[0] == board[i][j]) {
          unordered_map<int, bool> visited;
          if (dfsHelper(i, j, 0, visited, board, word)) {
            return true;
          }
        }
      }
    }

    return false;
  }

  bool dfsHelper(int i, int j, int index, 
    unordered_map<int, bool> &visited, const vector<vector<char>> &board,
    const string &word) {
    if (index == word.size() - 1) {
      return true;
    }
    visited[i * board[0].size() + j] = true;

    if (i + 1 < board.size() && 
      visited.find((i + 1) * board[0].size() + j) == visited.end() &&
      board[i + 1][j] == word[index + 1]) {
      if (dfsHelper(i + 1, j, index + 1, visited, board, word)) {
        return true;
      }
    }
    if (j + 1 < board[i].size() && 
      visited.find(i * board[0].size() + j + 1) == visited.end() &&
      board[i][j + 1] == word[index + 1]) {
      if (dfsHelper(i, j + 1, index + 1, visited, board, word)) {
        return true;
      }
    }
    if (i - 1 >= 0 && 
      visited.find((i - 1) * board[0].size() + j) == visited.end() &&
      board[i - 1][j] == word[index + 1]) {
      if (dfsHelper(i - 1, j, index + 1, visited, board, word)) {
        return true;
      }
    }
    if (j - 1 >= 0 && 
      visited.find(i * board[0].size() + j - 1) == visited.end() &&
      board[i][j - 1] == word[index + 1]) {
      if (dfsHelper(i, j - 1, index + 1, visited, board, word)) {
        return true;
      }
    }

    visited.erase(i * board[0].size() + j);
    return false;
  }
};

int main(void) {
  Solution sol;
  vector<vector<char>> board;
  vector<char> row = {'A', 'B', 'C', 'E'};
  board.push_back(row);
  row = {'S', 'F', 'E', 'S'};
  board.push_back(row);
  row = {'A', 'D', 'E', 'E'};
  board.push_back(row);

  cout << sol.exist(board, "ABCCED") << endl;
  cout << sol.exist(board, "SEE") << endl;
  cout << sol.exist(board, "ABCB") << endl;
  cout << sol.exist(board, "ABCESEEEFS") << endl;
}
