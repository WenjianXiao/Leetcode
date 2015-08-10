#include <iostream>
#include <vector>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    int min_cuts;
    int minCut(string s) {
        return minCut2(s);
    }
    /* Solution 1 : ispal[j][i] : j is the start pos, i is the length, ispal[j][i]
    ** dp[i] : i is the start index ,dp[i] is the minCut from i to the end.
    */
    int minCut1(string s) {
        int s_len = s.size();
        if (s_len == 0) {
            return 0;
        }
        int i,j;
        int *dp = (int *)malloc(s_len*sizeof(int));
        bool (*ispal)[s_len+1] = (bool (*)[s_len+1])malloc((s_len+1)*(s_len+1)*sizeof(bool));
        memset(ispal,true,sizeof(bool)*(s_len+1)*(s_len+1));
        for (i = 2; i <=s_len; i++) {
            for (j = 0; j<=s_len-i; j++) {
                ispal[j][i] = (s[j] == s[j+i-1]) && ispal[j+1][i-2];
            }
        }
        min_cuts = INT_MAX;
        dp[s_len-1] = 0;
        for (i = s_len-2; i >= 0; i--) {
            dp[i] = s_len-i-1;
            for (j = 1; j <= s_len-i; j++) {
                if (ispal[i][j]) {
                    if (j == s_len-i) dp[i] = 0;
                    else dp[i] = min(dp[i],dp[i+j]+1);
                }
            }
        }
        return dp[0];
    }
    /* Solution 2: ispal[j] <==> ispal[i][j] : i is the start pos, j is the end pos.
    ** ispal[i][j] = (s[i] == s[j]) && (j - i < 2 || ispal[i+1][j-1]) ---->
    ** ispal[j] = (s[i] == s[j]) && (j - i < 2 || ispal[j-1]) (i change for end to start);
    ** dp[i] : i is the start pos, dp[i] is the minCut from i to end; initially is is the end,
    ** it controls the length changing from 0 to s_size;
    */
    int minCut2(string s) {
        int s_size = s.size();
        vector<int> dp(s_size+1);
        vector<bool> ispal(s_size,true);
        dp[s_size] = -1;
        int i,j;
        for (i = s_size - 1; i >= 0; i--) {
            dp[i] = dp[i+1] + 1;
            for (j = s_size - 1; j >= i; j--) {
                ispal[j] = false;
                if (s[i] == s[j] && (j - i < 2 || ispal[j-1])) {
                    ispal[j] = true;
                    dp[i] = min(dp[i], dp[j+1] + 1);
                }
            }
        }
        return dp[0];
    }
};
int main()
{
    Solution solu;
    string a;
    cout << a.size() << endl;
    int res = solu.minCut(a);
    cout << "res:" << res << endl;
    cout << "Hello world!" << endl;
    return 0;
}
