#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int last=0;
        int i;
        for (i = 0; i < n; i++)
            if (i==0 || nums[i] != nums[i-1])
                nums[last++] = nums[i];
        return last;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
