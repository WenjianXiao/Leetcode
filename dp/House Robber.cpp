#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size == 0) return 0;
        int dp[3];
        dp[0] = 0;
        dp[1] = nums[0];
        int i;
        for (i = 2; i <= nums_size; i++) {
            dp[i%3] = max(dp[(i+1)%3] + nums[i-1], dp[(i+2)%3]);
        }
        return dp[nums_size%3];
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
