#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /** Solution :使用了hash表来记录每个数，然后依次对出现的每个数查找它附近的数
    ** 如果找到就擦除掉这个数
    **/
    int longestConsecutive(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums_size == 0 ) return 0;
        unordered_map<int, bool> mp;
        int i;
        int max_num = 0;
        for (i = 0; i < nums_size; i++) mp[nums[i]] = true;
        for (i = 0; i < nums_size; i++) {
            if (mp[nums[i]]){
                int num = consecutiveNum(nums[i],mp);
                if (num > max_num) max_num = num;
            }
        }
        return max_num;
    }
    int consecutiveNum(int n,map<int,bool> &mp)
    {
        int cnt = 0;
        int left = n;
        int right = n+1;
        while (1) {
            if (mp[left]) {
                cnt++;
                mp[left] = false;
                left--;
            } else break;
        }
        while (1) {
            if (mp[right]) {
                cnt++;
                mp[right] = false;
                right++;
            } else break;
        }
        return cnt;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
