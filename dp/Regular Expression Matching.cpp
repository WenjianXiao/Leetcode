#include <iostream>
#include <unordered_map>
#include <hash_map>
#include <map>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        const char *s1 = s.c_str();
        const char *p1 = p.c_str();
        return isMatch3(s1, p1);
    }
    /* Solution 1 */
    bool isMatch1(const char *s, const char *p) {
        while (*s) {
            if ((*p == *s || *p == '.') && *(p+1) != '*') {
                p++;
                s++;
            } else if (*p != 0 && *(p+1) == '*') {
                if (isMatch1(s, p+2)) return true;
                if (*p == *s || *p == '.') return isMatch1(s+1,p);
                else return false;
            } else return false;
        }
        while (*p) {
            if (*(p+1) == '*') p = p+2;
            else return false;
        }
        return true;
    }
    /* Solution 2 : simplify the Solution 1 */
    bool isMatch2(const char *s, const char *p) {
        if (*p == 0) return *s == 0;
        if (*(p+1) == '*') {
            if (isMatch2(s,p+2)) return true;
            while (*s == *p || (*p == '.' && *s != 0)) {
                s++;
                if (isMatch2(s,p+2)) return true;
            }
            return false;
        } else {
            if (*s == *p || (*p == '.' && *s != 0)) return isMatch2(s+1, p+1);
            return false;
        }
    }
    /* Solution 3 : dynamic programming :
    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'   (p[j-1] == '*');
    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')  (p[j-1] != '*')
    */
    bool isMatch3(const char *s, const char *p) {
        int s_len = strlen(s);
        int p_len = strlen(p);
        vector<bool> entry(p_len+1, false);
        vector<vector<bool>> dp(2, entry);
        int i,j;
        dp[0][0] = true;
        for(j = 1; j <= p_len; j++) {
            if (p[j-1] == '*') dp[0][j] = dp[0][j-2];
            else dp[0][j] = false;
        }
        for (i = 1; i <= s_len; i++) {
            for (j = 0; j <= p_len; j++) {
                if (j == 0) dp[i%2][j] = false;
                else {
                    if (p[j-1] == '*') {
                        dp[i%2][j] = dp[i%2][j-2] || (dp[(i+1)%2][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                    } else dp[i%2][j] = dp[(i+1)%2][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[s_len%2][p_len];
    }
};
int main()
{
    string a = "ab";
    string b = ".*c";
    Solution solu;
    solu.isMatch(a,b);
    cout << "Hello world!" << endl;
    return 0;
}
