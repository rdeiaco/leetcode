#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
    vector<pair<int, int>> keypoints;

    keypoints = divConquer(buildings, 0, buildings.size());

    return keypoints;
  }

  vector<pair<int, int>> divConquer(vector<vector<int>> &buildings, 
    int start_index, int end_index) {
    vector<pair<int, int>> keypoints;

    if (start_index >= end_index) {
      return keypoints;
    }
    if (end_index - start_index == 1) {
      keypoints.push_back(pair<int, int>(buildings[start_index][0], buildings[start_index][2]));
      keypoints.push_back(pair<int, int>(buildings[start_index][1], 0));
      return keypoints;
    }
    else {
      int mid = start_index + (end_index - start_index) / 2;
      vector<pair<int, int>> kp_1, kp_2;
      kp_1 = divConquer(buildings, start_index, mid);
      kp_2 = divConquer(buildings, mid, end_index); 
      if (kp_1.size() == 0) {
        return kp_2;
      }
      if (kp_2.size() == 0) {
        return kp_1;
      }

      int i = 0;
      int j = 0;
      int curr_height_1 = 0;
      int curr_height_2 = 0;
      while (i < kp_1.size() || j < kp_2.size()) {
        if (i == kp_1.size()) {
          keypoints.push_back(kp_2[j]);
          j++;
          continue;
        }
        if (j == kp_2.size()) {
          keypoints.push_back(kp_1[i]);
          i++;
          continue;
        }
        
        if (kp_1[i].first < kp_2[j].first) {
          // This keypoint is the dominant height over the other set.
          if (kp_1[i].second > curr_height_2) {
            keypoints.push_back(kp_1[i]);
          }
          // This results in a transition of domination to the other set.
          else if (curr_height_1 > curr_height_2) {
            keypoints.push_back(pair<int, int>(kp_1[i].first, curr_height_2));
          }
          curr_height_1 = kp_1[i].second;
          i++;
        }
        else if (kp_1[i].first > kp_2[j].first) {
          if (kp_2[j].second > curr_height_1) {
            keypoints.push_back(kp_2[j]);
          }
          else if (curr_height_2 > curr_height_1) {
            keypoints.push_back(pair<int, int>(kp_2[j].first, curr_height_1));
          }
          curr_height_2 = kp_2[j].second;
          j++;
        }
        else {
          int height = max(kp_1[i].second, kp_2[j].second);
          if (height != max(curr_height_1, curr_height_2)) {
            keypoints.push_back(pair<int, int>(kp_1[i].first, height));
          }
          curr_height_1 = kp_1[i].second;
          curr_height_2 = kp_2[j].second;
          i++;
          j++;
        }
      }


      return keypoints;
    }
  }
};

int main(void) {
  Solution sol;

  vector<vector<int>> buildings;
  vector<int> building = {2, 9, 10};
  buildings.push_back(building);
  building = {3, 7, 15};
  buildings.push_back(building);
  building = {5, 12, 12};
  buildings.push_back(building);
  building = {15, 20, 10};
  buildings.push_back(building);
  building = {19, 24, 8};
  buildings.push_back(building);

  vector<pair<int, int>> kp = sol.getSkyline(buildings);
  for (pair<int, int> p : kp) {
    cout << p.first << " " << p.second << endl;
  }


}
