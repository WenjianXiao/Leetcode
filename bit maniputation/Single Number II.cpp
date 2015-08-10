#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber1(vector<int>& nums) {
        int nums_size = nums.size();
        int i,k;
        int res = 0;
        for(k = 0; k < 32; k++) {
            int one_count = 0;
            int zero_count = 0;
            for(i=0;i<nums_size;i++) {
                if (((nums[i]>>k) & 1)) one_count++;
                else zero_count++;
            }
            if (one_count % 3) {
                res = (res | (1<<k));
            }
        }
        return res;
    }
    int singleNumber2(vector<int>& nums) {
        int nums_size = nums.size();
        int i,one,two,three;
        one=two=three=0;
        for (i = 0; i < nums_size; i ++) {
            three = two & nums[i];  //已经出现了两次，还出现了一次
            two = two | one&nums[i]; //出现了1次又出现了1次，在加上以前已经出现了2次的，为新的出现了2次的
            one = one | nums[i]; //出现了1次
            //将出现3次的其出现1次2次全部抹去,因为只有出现三次时，才可以抹掉。
            two = two & (~three);
            one = one & (~three);
        }
        return one;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
