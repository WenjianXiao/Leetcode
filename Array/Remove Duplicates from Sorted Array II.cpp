#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicates_2(nums);
    }
    int removeDuplicates_1(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size == 0) return 0;
        int i;
        int len=0;
        int last = 0;
        int last_pos=1;
        for(i = 1; i < nums_size; i++) {
            if (nums[i] == nums[last]) {
               if (i - last < 2) nums[last_pos++] = nums[i];
            } else {
                last = i;
                nums[last_pos++] = nums[i];
            }
        }
        return last_pos;
    }
    int removeDuplicates_2(vector<int>& nums) {
        int last = 2, n = nums.size(),i;
        if (n <= 2) return n;
        for (i = 2; i < n; i++) {
            if (nums[i] != nums[last-2]) nums[last++] = nums[i];
        }
        return last;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
