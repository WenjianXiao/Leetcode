#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int i,cnt=0;
        vector<int> res;
        for (i = 0; i < n; i++) {
            if (mp.find(nums[i]) == mp.end() && cnt < 2) { mp[nums[i]] = 1; cnt++;}
            else if (mp.find(nums[i]) == mp.end() && cnt == 2) {
                unordered_map<int,int>::iterator it = mp.begin();
                while(it != mp.end()) {
                    mp[it->first]--;
                    if (it->second == 0) {
                        mp.erase((it++)->first);
                        cnt--;
                    } else it++;
                }
            } else mp[nums[i]]++;
        }
        unordered_map<int,int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            int cnt = 0;
            for (i = 0; i < n; i++) {
                if (it->first == nums[i]) cnt++;
            }
            if (cnt > n/3) res.push_back(it->first);
        }
        return res;
    }
};

int main()
{
    int a[] = {1};
    vector<int> nums(1);
    int i;
    for (i = 0; i < nums.size(); i++) nums[i] = a[i];
    Solution solu;
    vector<int> res = solu.majorityElement(nums);
    cout << res.size() << endl;
    for (i = 0; i < res.size(); i++) cout << res[i] << endl;
    cout << "Hello world!" << endl;
    return 0;
}
