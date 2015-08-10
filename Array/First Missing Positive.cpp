#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /** Solution 1: Swap elements in nums and make all element in nums satify nums[i] == i+1;
    ** if nums[i] != i+1 && nums[i] > 0, we can swap nums[i] ---> nums[nums[i]-1].but we must
    ** guarantee nums[i] - 1 < n && nums[i] != nums[nums[i]-1];
    **
    ** Then pick out the first one that does not satisfy A[i] == i + 1.
    **/
    int firstMissingPositive(vector<int>& nums) {
        int i,res,n = nums.size();
        for (i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] - 1 < n && nums[i] != i + 1 && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i] - 1]);
                if (nums[i] > 0) i--;
            }
        }
        for (i = 0; i < n; i++) {
            if (nums[i] != i+1) return i+1;
        }
        return i+1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
