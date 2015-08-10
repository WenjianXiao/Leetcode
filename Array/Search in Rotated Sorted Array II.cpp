#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        search1(nums, target);
    }
    /** Solution 2: binary_find. there are 3 cases:
    ** nums[mid] > nums[l] : so [l,mid] 区间内单调递增的！如果target在这个范围内，那么r = mid - 1;反之, l = mid + 1;
    ** nums[mid] < nums[l] : 所以[l,mid]内先递增，下降到某点后再递增。如果target不在这两段内，那么l = mid + 1;反之r = mid - 1;
    ** nums[mid] = nums[l] : 无法判断[mid,l]的情况，但是如果nums[mid] != nums[r],说明[mid,l]之间是不变的。那么l = mid + 1;
    ** 反之，只能说明l,r这两点不满足条件。
    **/
    bool search2(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (target == nums[mid]) return true;
            else if (nums[mid] > nums[l]) {
                if (target >= nums[l] && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else if (nums[mid] < nums[l]) {
                if (target > nums[mid] && target < nums[l]) l = mid + 1;
                else r = mid - 1;
            } else {
                if (nums[mid] == nums[r]) {
                    l++; r--;
                } else {
                    l = mid + 1;
                }
            }
        }
        return false;
    }
    /** Solution 1: 这个方法的基本思想是先找到转折点，即最小的那个点。然后再根据target的值来判断查找哪一段。
    ** 因为我们知道[0,mid)单调递增，[mid, n-1]单调递增的。如果target > nums[n-1]，那么就在前一段中查找。否则在
    ** 后一段中查找。
    **/
    bool search1(vector<int>& nums, int target) {
        int nums_size = nums.size();
        if (nums_size == 0) return false;
        int mid_point = find_mid_point(nums);
        bool res=false;
        if (target > nums[nums_size-1]) {
            res = b_find(nums,0,mid_point-1,target);
        } else {
            res = b_find(nums,mid_point,nums_size-1,target);
        }
        return res;
    }
    /** 当nums[mid]和nums[end]不等时，我们是很好去做判断的转折点的范围的。
    ** 当nums[mid] > nums[end]，说明肯定在[mid+1, end]段。
    ** 当nums[mid] < nums[end],说明在[l, mid]段。
    ** 当相等时，无法判断是在哪一段上，那么只有遍历[l,r]这段范围，找到一个不等于它的
    ** 做处理即可。
    **/
    int find_mid_point(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int end = right;
        while (left<right) {
            int mid = (left+right)/2;
            if (nums[mid] > nums[end]) left = mid+1;
            else if (nums[mid] < nums[end]) right = mid;
            else {
                int i;
                for (i = mid; i <= right; i++) {
                    if (nums[i] > nums[end]) {
                        left = i+1;
                        break;
                    }
                    else if (nums[i] < nums[end]) {
                        return i;
                    }
                }
                if (i == right+1) right = mid;
            }
        }
        return left;
    }
    bool b_find(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = (left+right)/2;
            if (target == nums[mid]) return true;
            else if (target < nums[mid]) right = mid - 1;
            else left = mid+1;
        }
        return false;
    }
};
int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    Solution solu;
    bool res = solu.search(nums,1);
    cout << res << endl;
    cout << "Hello world!" << endl;
    return 0;
}
