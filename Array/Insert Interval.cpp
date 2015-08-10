#include <iostream>
#include <vector>

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

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        return insert_2(intervals, newInterval);
    }
    /** Solution 1: find the last index whose start <= newInterval.start, the index is s_inter;
    **  and find the last index whose start <= newInter.end, the index is e_inter;
    **  merge the interval between s_inter and e_inter;
    **/
    vector<Interval> insert_1(vector<Interval>& intervals, Interval newInterval) {
        int i_size = intervals.size();
        vector<Interval> res;
        res.clear();
        int s_inter = find_first(intervals, newInterval.start);
        int e_inter = find_first(intervals, newInterval.end);
        int start=newInterval.start;
        int pre_idx;
        if (s_inter==-1) {
            pre_idx = -1;
        } else {
            if (newInterval.start <= intervals[s_inter].end) {
                start = intervals[s_inter].start;
                pre_idx = s_inter - 1;
            } else pre_idx = s_inter;
        }
        int end = newInterval.end;
        int nxt_idx;
        if (e_inter == -1) {
            nxt_idx = 0;
        } else {
            if (newInterval.end <= intervals[e_inter].end) {
                end = intervals[e_inter].end;
            }
            nxt_idx = e_inter+1;
        }
        Interval new_inter(start, end);
        int i;
        for (i = 0; i <= pre_idx; i++) res.push_back(intervals[i]);
        res.push_back(new_inter);
        for (i=nxt_idx; i < i_size; i++) res.push_back(intervals[i]);
        return res;
    }
    int find_first(vector<Interval> & intervals, int val) {
        int i_size = intervals.size();
        int left = 0;
        int right = i_size - 1;
        while (left <= right) {
            int mid = (left+right)/2;
            if (intervals[mid].start == val) return mid;
            else if (intervals[mid].start > val) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
    /** Solution 2 :
    ** 1 pass the intervals of end < newInterval.start
    ** 2 merge newInterval with those of start <= newInterval.end
    ** 3 push newInterval
    ** 4 pass the rest intervals
    **/
    vector<Interval> insert_2(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        int i;
        vector<Interval> res;
        for (i = 0; i < n && intervals[i].end < newInterval.start; i++) res.push_back(intervals[i]);
        for (; i < n && intervals[i].start <= newInterval.end; i++) {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
        res.push_back(newInterval);
        for (;i < n; i++) res.push_back(intervals[i]);
        return res;
    }
};
int main()
{
    Interval inter1(1,2);
    Interval inter2(3,5);
    Interval inter3(6,7);
    Interval inter4(8,10);
    Interval inter5(12,16);
    Interval inter6(4,9);
    vector<Interval> init;
    init.push_back(inter1);
    init.push_back(inter2);
    init.push_back(inter3);
    init.push_back(inter4);
    init.push_back(inter5);
    vector<Interval> res;
    Solution s;
    res = s.insert(init, inter6);
    int i;
    for (i = 0; i < res.size();i++) {
        cout << res[i].start << " " << res[i].end << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
