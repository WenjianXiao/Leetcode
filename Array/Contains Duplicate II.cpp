#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int nums_size = nums.size();
        int i = 0, j = 0;
        map<int,int> mp;
        mp.clear();
        for(i = 0; i < nums_size; i++) {
            if (i-j>k) mp.erase(nums[j++]);
            if (mp[nums[i]] != 0) return true;
            mp[nums[i]] = i+1;
        }
        return false;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
