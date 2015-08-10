#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        return trap_2(height);
    }
    int trap_1(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector<int> l_max_h(n, height[0]);
        vector<int> r_max_h(n ,height[n-1]);
        int i, maxh = height[0];
        for (i = 0; i < n; i++) {
            if (height[i] > maxh) maxh = height[i];
            l_max_h[i] = maxh;
        }
        maxh = height[n-1];
        for (i = n-1; i >= 0; i--) {
            if (height[i] > maxh) maxh = height[i];
            r_max_h[i] = maxh;
        }
        int res = 0;
        for (i = 0; i < n; i++) {
            int water = min(l_max_h[i], r_max_h[i]) - height[i];
            res += (water > 0 ? water : 0);
        }
        return res;
    }
    int trap_2(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        int l_max_h = height[0], r_max_h = height[n-1];
        int left = 1, right = n - 2;
        int res = 0;
        while (left <= right) {
            if (l_max_h <= r_max_h) {
                int water = l_max_h - height[left];
                res += (water > 0 ? water : 0);
                l_max_h = max(l_max_h, height[left]);
                left++;
            } else {
                int water = r_max_h - height[right];
                res += (water > 0 ? water : 0);
                r_max_h = max(r_max_h, height[right]);
                right--;
            }
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
