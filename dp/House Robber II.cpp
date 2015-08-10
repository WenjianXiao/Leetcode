#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size == 0) return 0;
        int max1 = getMaxVal(nums,2,nums_size-2) + nums[0];
        int max2 = getMaxVal(nums,1,nums_size-1);
        return max(max1, max2);
    }
    int getMaxVal(vector<int>& nums,int s,int e) {
        if (e < s) return 0;
        int dp[3];
        dp[(s+2)%3] = 0;
        dp[s%3] = nums[s];
        int i;
        for (i = s+1; i <=e; i++) {
            dp[i%3] = max(dp[(i+2)%3], dp[(i+1)%3] + nums[i]);
        }
        return dp[e%3];
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
