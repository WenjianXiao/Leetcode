#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        return jump1(nums);
    }
    /** Solution 1: cur_len represents current reachable maximum length,nxt_len represents
    ** the maximum length that next step can reach.
    **/
    int jump(vector<int>& nums) {
        int cur_len = 0, nxt_len = 0;
        int i, n = nums.size();
        int step = 0;
        for (i = 0; i < n; i++) {
            if (i <= cur_len) {
                nxt_len = max(nxt_len, nums[i] + i);
            } else {
                if (i > nxt_len) return -1;
                cur_len = nxt_len;
                nxt_len = i + nums[i];
                step++;
            }
        }
        return step;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
