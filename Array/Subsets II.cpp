#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        return subsetsWithDup_1(nums);
    }
    vector<vector<int>> subsetsWithDup_1(vector<int>& nums) {
        vector<vector<int>> res;
        int nums_size = nums.size();
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        subsetsWithDupHelper(res,nums,0,nums_size,tmp);
        return res;
    }
    void subsetsWithDupHelper(vector<vector<int>> &res, vector<int>& nums, int kth, int nums_size,vector<int> &tmp) {
        res.push_back(tmp);
        int i;
        for(i=kth;i<nums_size;i++) {
            if (i != kth && nums[i] == nums[i-1]) continue;
            tmp.push_back(nums[i]);
            subsetsWithDupHelper(res,nums,i+1,nums_size,tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup_2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        res.push_back(vector<int>(0));
        int i,j,n=nums.size();
        int pre_size = 0;
        for (i = 0; i < n; i++) {
            int num = res.size();
            for (j = 0; j < num; j++) {
                if (i == 0 || nums[i] != nums[i-1] || j >= pre_size) {
                    res.push_back(res[j]);
                    res.back().push_back(nums[i]);
                }
            }
            pre_size = num;
        }
        return res;
    }
};
int main()
{
    vector<int> nums(1,0);
    Solution solu;
    solu.subsetsWithDup(nums);
    cout << "Hello world!" << endl;
    return 0;
}
