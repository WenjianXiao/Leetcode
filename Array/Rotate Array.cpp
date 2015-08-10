#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        int n = nums.size();
        int l1 = n - k%n, l2 = k%n;
        reverse(nums.begin(), nums.begin()+l1);
        reverse(nums.begin()+l1, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
