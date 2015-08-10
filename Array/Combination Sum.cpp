#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> entry;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return combinationSum1(candidates, target);
    }
    vector<vector<int>> combinationSum1(vector<int>& candidates, int target) {
        res.clear();
        entry.clear();
        sort(candidates.begin(),candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        int n = candidates.size();
        combinationSumHelper1(candidates, target, 0, n);
        return res;
    }
    void combinationSumHelper1(vector<int>& candidates, int target, int index, int n) {
        if (target == 0) {
            res.push_back(entry);
            return ;
        }
        if (target < 0) return;
        int i;
        for (i = index; i < n; i++) {
            entry.push_back(candidates[i]);
            combinationSumHelper1(candidates, target - candidates[i], i, n);
            entry.pop_back();
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
