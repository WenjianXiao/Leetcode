#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};
bool cmp (const Interval &inter1, const Interval &inter2) {
    return inter1.start < inter2.start ? true : (inter1.start == inter2.start ? inter1.end < \
                                                 inter2.end : false);
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int i_size = intervals.size();
        vector<Interval> res;
        res.clear();
        if (i_size == 0) return res;
        sort(intervals.begin(),intervals.end(),cmp);
        Interval last = intervals[0];
        int i;
        for (i = 1; i < i_size; i++) {
            if (intervals[i].start <= last.end) {
                last.end = max(last.end,intervals[i].end);
            } else {
                res.push_back(last);
                last = intervals[i];
            }
        }
        res.push_back(last);
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
