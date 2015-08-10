#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> entry;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        return combinationSum2_1(candidates,target);
    }
    vector<vector<int>> combinationSum2_1(vector<int>& candidates, int target) {
        res.clear();
        entry.clear();
        sort(candidates.begin(),candidates.end());
        combinationSumHelper2_1(candidates,target,0,candidates.size());
        return res;
    }
    void combinationSumHelper2_1(vector<int>& candidates, int target, int idx, int n) {
        if (target == 0) {
            res.push_back(entry);
            return ;
        }
        if (target < 0) return ;
        int i;
        unordered_map<int,int> mp;
        mp.clear();
        for (i = idx; i < n; i++) {
            if (mp[candidates[i]] == 0) {
                entry.push_back(candidates[i]);
                combinationSumHelper2_1(candidates, target-candidates[i], i+1, n);
                entry.pop_back();
                mp[candidates[i]]++;
            }
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
