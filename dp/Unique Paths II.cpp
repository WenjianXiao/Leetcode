#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        int i,j;
        vector<int> dp(n, 0);
        if (obstacleGrid[0][0] == 0) dp[0] = 1;
        else dp[0] = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (j == 0) dp[j] = (obstacleGrid[i][j] == 1 ? 0 : dp[j]);
                else if (i == 0) dp[j] = (obstacleGrid[i][j] == 1 ? 0 : dp[j-1]);
                else dp[j] = (obstacleGrid[i][j] == 1 ? 0 : dp[j-1] + dp[j]);
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
