#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size == 0) return 0;
        if (s == 0) return 1;
        int head=0,tail=0;
        int sum = 0;
        int min_len=nums_size + 1;
        while (head <= tail && tail < nums_size) {
            sum += nums[tail];
            while (sum >= s && head <= tail) {
                min_len = min(min_len, tail - head + 1);
                sum -= nums[head++];
            }
            tail++;
        }
        return min_len == nums_size + 1 ? 0 : min_len;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
