#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int head=0;
        int tail=nums.size()-1;
        int nums_size = tail+1;
        int i;
        for(i=0;i<=tail;i++) {
            if (nums[i] == 0) {
                if (i != head) swap(nums[i],nums[head]);
                head++;
            }
            if (nums[i] == 2 && i < tail) {
                swap(nums[i],nums[tail]);
                tail--;
                i--;
            }
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
