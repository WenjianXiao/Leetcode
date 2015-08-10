#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <map>
#include <cstring>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace __gnu_cxx;
using namespace std;
class Solution {
public:
    /*Solution 1: sort num*/
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        return nums[size/2];
    }
    /*Solution 2: moore voting algorithm*/
    int majorityElement1(vector<int>& nums) {
        int size = nums.size();
        int cand;
        int i,count=0;
        for (i = 0; i < size; i++) {
            if (count == 0) {cand = nums[i]; count++;}
            else {
                if (nums[i] == cand) count++;
                else count--;
            }
        }
        return cand;
    }
    /*Solution 3: bit maniputation*/
    int majorityElement2(vector<int>& nums) {
        int size = nums.size();
        int i,j,res=0;
        for (i = 0; i < 32; i++) {
            int zero = 0, one = 0;
            for (j = 0; j < size; j++) {
                if (nums[j] & (1<<i)) one++;
                else zero++;
            }
            if (zero < one) res |= (1<<i);
        }
        return res;
    }
    /*Solution 4: hash table*/
    int majorityElement3(vector<int>& nums) {
        int size = nums.size();
        int i;
        unordered_map<int,int> hmp;
        for (i = 0; i < size; i++) {
            if (++hmp[nums[i]] > size/2) return nums[i];
        }
        return 0;
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
