#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        return numDistinct1(s,t);
    }
    /** Solution 1: dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; (s[i-1] == t[j-1])
    ** dp[i-1][j-1] determins its directory of j (from t_size to 0);
    **/
    int numDistinct1(string s, string t) {
        int s_size = s.length();
        int t_size = t.length();
        if (s_size < t_size) return 0;
        if (t_size == 0) return 1;
        vector<int> dp(t_size+1, 0);
        int i,j;
        for(i = 0; i <= s_size; i++) {
            for (j = t_size; j>=0; j--) {
                if (j == 0) dp[j] = 1;
                else if (i < j) dp[j] = 0;
                else if (s[i-1] == t[j-1]) dp[j]=dp[j] + dp[j-1];
            }
        }
        return dp[t_size];
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
