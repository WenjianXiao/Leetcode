#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        return calculateMinimumHP1(dungeon);
    }
    /** Solution 1 : dp[i][j] : 在到达(i,j)这点之前必须保证的最小血量。
    ** 为什么不用dp[i][j]作为到达(i,j)的最小血量呢？dp[i][j] --> dp[i][j+1]无法求出，因为求最小血量的过程并没有
    **将它经过路程的正数包含进来。这样求出的dp[i][j+1]肯定是比实际的大。
    **同时必须保证dp[i][j]大于等于0，比如（-3,5）,不然求出的值比实际的小。
    **/
    int calculateMinimumHP1(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        if (r == 0) return 1;
        int c = dungeon[0].size();
        if (c == 0) return 1;
        int i,j;
        vector<int> dp(c);
        for (i = r - 1; i >= 0; i--) {
            for (j = c - 1; j >= 0; j--) {
                if (i == r - 1 && j == c - 1) dp[j] = max(-dungeon[i][j],0);
                else if (i == r - 1) dp[j] = max(dp[j+1] - dungeon[i][j],0);
                else if (j == c - 1) dp[j] = max(dp[j] - dungeon[i][j],0);
                else {
                    dp[j] = max(min(dp[j+1],dp[j]) - dungeon[i][j],0);
                }
            }
        }
        return dp[0]+1;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
