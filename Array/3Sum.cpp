#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        res.clear();
        int n = nums.size();
        int i;
        sort(nums.begin(),nums.end());
        for (i = 0; i < n-2 && nums[i]<=0; i++) {
            if (i!=0 && nums[i] == nums[i-1]) continue;
            int left=i+1;
            int right = n - 1;
            while (left < right) {
                LL sum = (LL)nums[i] + nums[left] + nums[right];
                if (sum < 0) left++;
                else if (sum > 0) right--;
                else {
                    vector<int> entry;
                    entry.push_back(nums[i]);
                    entry.push_back(nums[left]);
                    entry.push_back(nums[right]);
                    while(left < right && nums[left+1] == nums[left]) left++;
                    while(left < right && nums[right-1] == nums[right]) right--;
                    left++;
                    right--;
                    res.push_back(entry);
                }
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
