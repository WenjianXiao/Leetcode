#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleave2(s1,s2,s3);
    }
    /* Solution 1 */
    bool isInterleave1(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1+len2!=len3) return false;
        bool dp[len1+1][len2+1];
        int i,j;
        for (i = 0; i <= len1; i++) {
            for (j = 0; j <= len2; j++) {
                if (i == 0 && j == 0) dp[i][j]=true;
                else if (i == 0) {
                    dp[i][j] = dp[i][j-1] && (s3[i+j-1] == s2[j-1]);
                } else if (j == 0) {
                    dp[i][j] = dp[i-1][j] && (s3[i+j-1] == s1[i-1]);
                } else {
                    dp[i][j] = (dp[i][j-1] && (s3[i+j-1] == s2[j-1])) ||
                                (dp[i-1][j] && (s3[i+j-1] == s1[i-1]));
                }
            }
        }
        return dp[len1][len2];
    }
    /* Solution 2: simplify the solution 1 */
    bool isInterleave2(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len1 + len2 != len3) return false;
        vector<bool> dp(len2+1, false);
        int i,j;
        for (i = 0; i <= len1; i++) {
            for (j = 0; j <= len2; j++) {
                if (i == 0 && j == 0) dp[j] = true;
                else if (i == 0) dp[j] = (dp[j-1] && s3[i+j-1] == s2[j-1]);
                else if (j == 0) dp[j] = (dp[j] && s3[i+j-1] == s1[i-1]);
                else {
                    dp[j] = (dp[j-1] && s3[i+j-1] == s2[j-1]) || (dp[j] && s3[i+j-1] == s1[i-1]);
                }
            }
        }
        return dp[len2];
    }
};
int main()
{
    Solution solu;
    string s1="";
    string s2="";
    string s3="";
    bool res = solu.isInterleave(s1,s2,s3);
    cout << res << endl;
    cout << "Hello world!" << endl;
    return 0;
}
