#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        mp.clear();
        int nums_size = nums.size();
        int i;
        for(i=0;i<nums_size;i++) {
            if (mp[nums[i]] == false) mp[nums[i]] = true;
            else return true;
        }
        return false;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
