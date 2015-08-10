#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int nums_size = nums.size();
        int res = 0;
        int i;
        for (i = 0; i < nums_size; i++) {
            res = res^nums[i];
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
