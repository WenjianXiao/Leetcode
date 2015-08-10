#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left+right)/2;
            if ((mid == left || nums[mid-1] < nums[mid]) && (mid == right || nums[mid] > nums[mid+1]))
                return mid;
            else if (mid != left && nums[mid-1] > nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
