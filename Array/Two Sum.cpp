#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
        return a.first < b.first;
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return twoSum2(nums, target);
    }
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> res;
        vector<pair<int, int>> snums;
        res.clear();
        snums.clear();
        int i,n = nums.size();
        for (i = 0; i < n; i++) {
            snums.push_back(pair<int,int>(nums[i],i+1));
        }
        sort(snums.begin(),snums.end(),cmp);
        int l = 0, r = n - 1;
        while (l < r) {
            if (snums[l].first + snums[r].first == target) {
                res.push_back(min(snums[l].second, snums[r].second));
                res.push_back(max(snums[l].second, snums[r].second));
                return res;
            } else if (snums[l].first + snums[r].first < target) l++;
            else r--;
        }
        return res;
    }
    /* Solution 2 : hash */
    vector<int> twoSum2(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        int i;
        unordered_map<int,int> mp;
        mp.clear();
        for (i = 0; i < n; i++) {
            if (mp.find(target-nums[i]) != mp.end()) {
                res.push_back(mp[target-nums[i]]);
                res.push_back(i+1);
                return res;
            } else {
                mp[nums[i]] = i + 1;
            }
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
