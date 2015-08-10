#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return searchRange1(nums, target);
    }
    vector<int> searchRange1(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int l = getBound(nums, target, -1);
        int r = getBound(nums, target, 1);
        if (l <= r) {
            res[0] = l;
            res[1] = r;
        }
        return res;
    }
    /** Solution 1: dir == -1 ,找左边界，就是第一个大于等于它的数。
    **dir == 1,就是找右边界，就是最后一个小于等于它的数
    **/
    int getBound(vector<int>& nums, int target, int dir) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] < target) l = mid + 1;
            else if (nums[mid] > target) r = mid - 1;
            else if (dir == -1) r = mid - 1;
            else l = mid + 1;
        }
        if (dir == -1) return l;
        else return r;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
