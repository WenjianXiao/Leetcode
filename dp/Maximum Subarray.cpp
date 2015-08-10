#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last,max_sum;
        last=max_sum=nums[0];
        int i;
        for(i=1;i<nums.size();i++) {
            if (last > 0) last += nums[i];
            else last = nums[i];
            max_sum = max(max_sum, last);
        }
        return max_sum;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
