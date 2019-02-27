#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

struct interval_less {
  bool operator()(const Interval &i1, const Interval &i2) {
    return i1.start < i2.start;
  }
};

class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.size() <= 1) {
      return intervals;
    }
    sort(intervals.begin(), intervals.end(), interval_less());

    vector<Interval> merged_intervals;
    int j = 1;
    int start = intervals[0].start;
    int end = intervals[0].end;
    while (j < intervals.size()) {
      if (intervals[j].start <= end) {
        end = max(intervals[j].end, end);
      }
      else {
        merged_intervals.push_back(Interval(start, end));
        start = intervals[j].start;
        end = intervals[j].end;
      }

      j++;
      if (j == intervals.size()) {
        merged_intervals.push_back(Interval(start, end));
      }
    }

    return merged_intervals;
  }
};

int main(void) {
  Solution sol;
  vector<Interval> intervals;
  intervals.push_back(Interval(1, 3));
  intervals.push_back(Interval(2, 6));
  intervals.push_back(Interval(8, 10));
  intervals.push_back(Interval(15, 18));
  intervals = sol.merge(intervals);

  for (Interval i : intervals) {
    cout << i.start << " " << i.end << endl;
  }
}
