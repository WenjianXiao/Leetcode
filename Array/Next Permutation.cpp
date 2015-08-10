#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        int i;
        for (i = n-1; i>=1; i--) {
            if (nums[i] > nums[i-1]) break;
        }
        i--;
        if (i >= 0) {
            int first_bigger = my_binary_search(nums, i+1, nums[i]);
            swap(nums[i], nums[first_bigger]);
        }
        sort(nums.begin()+i+1, nums.end());
    }
    int my_binary_search(vector<int>& nums, int idx, int val) {
        int l = idx, r = nums.size() - 1;
        while (l < r) {
            int mid = (l+r+1)/2;
            if (nums[mid] <= val) r = mid-1;
            else l = mid;
        }
        return l;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
