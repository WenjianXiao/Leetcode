#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    /* dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + grid[i][j]; ---->
    ** dp[j] = min(dp[j],dp[j-1]) + grid[i][j]; (j change from max to min);
    **/
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        if (m == 0) return 0;
        vector<int> dp(m, 0);
        dp[0] = triangle[0][0];
        int i,j;
        for(i = 1; i < m; i++) {
            for (j = i; j >= 0; j--) {
                if (j == 0) dp[j] = dp[j] + triangle[i][j];
                else if (j == i) dp[j] = dp[j-1] + triangle[i][j];
                else {
                    dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
                }
            }
        }
        int min_val = dp[0];
        for (i = 1; i < m; i++) if (dp[i] < min_val) min_val = dp[i];
        return min_val;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
