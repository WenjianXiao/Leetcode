#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJump1(nums);
    }
    /** Solution 1: cur_len represents current reachable maximum length,nxt_len represents
    ** the maximum length that next step can reach.
    **/
    bool canJump1(vector<int>& nums) {
        int cur_len = 0, nxt_len = 0;
        int i, n = nums.size();
        int step = 0;
        for (i = 0; i < n; i++) {
            if (i <= cur_len) {
                nxt_len = max(nxt_len, nums[i] + i);
            } else {
                if (i > nxt_len) return false;
                cur_len = nxt_len;
                nxt_len = i + nums[i];
                if (cur_len >= n-1) return true;
            }
        }
        return true;
    }
    bool canJump2(vector<int>& nums) {
        int start = 0, end = 0;
        int n = nums.size();
        while (start <= end && end <= n-1) {
            end = max(end, start+nums[start]);
            start++;
        }
        return end >= n-1;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
