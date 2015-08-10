#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int last = 0,i;
        for(i=0;i<n;i++) {
            if (nums[i] != val) nums[last++] = nums[i];
        }
        return last;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
