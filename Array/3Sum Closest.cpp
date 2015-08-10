#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        LL min_dis = fabs(nums[0] + nums[1] + nums[2] - target);
        LL res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        int i;
        for (i = 0; i < n - 2; i++) {
            if (i !=0 && nums[i] == nums[i-1]) continue;
            int left = i+1,right = n-1;
            while (left < right) {
                LL sum = nums[i] + nums[left] +nums[right];
                if (sum == target) return sum;
                else if (sum > target) right--;
                else left++;
                if (fabs(sum-target) < min_dis) {
                    min_dis = fabs(sum-target);
                    res = sum;
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
