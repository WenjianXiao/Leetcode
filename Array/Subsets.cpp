#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsets_2(nums);
    }
    vector<vector<int>> subsets_1(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        subsets_helper(nums,0,nums.size());
        return res;
    }
    void subsets_helper(vector<int> &nums, int kth, int n) {
        int i;
        res.push_back(tmp);
        for (i = kth; i < n; i++) {
            tmp.push_back(nums[i]);
            subsets_helper(nums,i+1,n);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets_2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        res.push_back(vector<int>(0));
        int i,j,n=nums.size();
        for (i = 0; i < n; i++) {
            int num = res.size();
            for (j = 0; j < num; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
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
