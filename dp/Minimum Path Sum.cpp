#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        int i,j;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (j == 0) dp[j] = dp[j] + grid[i][j];
                else if (i == 0) dp[j] = dp[j-1] + grid[i][j];
                else dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
            }
        }
        return dp[n-1];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
