#include <iostream>
using namespace std;

#define my_min(a,b) ((a > b) ? b : a)
#define my_max(a,b) ((a > b) ? a : b)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size == 0) return 0;
        long long dp_min,dp_max;
        dp_min = dp_max = nums[0];
        int i;
        int ans = dp_max;
        for (i = 1; i < nums_size; i++) {
            if (nums[i] > 0){
                dp_min = my_min(nums[i], dp_min*nums[i]);
                dp_max = my_max(nums[i], dp_max*nums[i]);
            } else {
                long long tmp = dp_max;
                dp_max = my_max(nums[i], dp_min * nums[i]);
                dp_min = my_min(nums[i], tmp * nums[i]);
            }
            if (dp_max > ans) ans = dp_max;
        }
        return ans;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
