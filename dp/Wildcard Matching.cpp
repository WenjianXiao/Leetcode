#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

//recursive
/*char *count = NULL;
int isMatch(char* s, char* p) {
    if (s == NULL || p == NULL) return 0;
    char *s1 = s;
    while(*s1) {
        if (*p == '?' || *s1 == *p) {
            s1++;
            p++;
        } else if (*p == '*') {
            for(;*(p+1) == '*';p++);
            count = p;
            if (isMatch(s1, p+1)) {
                return 1;
            }
            if (count != p) return 0;
            else s1++;
        } else return 0;
    }
    count = NULL;
    while(*p == '*') p++;
    if (*s1 == *p) return 1;
    return 0;
}*/
//recursive
/*int isMatch(char* s, char* p) {
    if (s == NULL || p == NULL) return 0;
    char *s1 = NULL;
    char *p1 = NULL;
    while(*s) {
        if (*p == '?' || *s == *p) {
            s++;
            p++;
        } else if (*p == '*') {
            for(;*(p+1) == '*';p++);
            s1 = s;
            p1 = p;
            p++;
        } else if (s1) {
            s=s1+1;
            p=p1+1;
            s1++;
        } else return 0;
    }
    while(*p == '*') p++;
    if (*s == *p) return 1;
    return 0;
}
int isMatch(char* s, char* p) {
    if (s == NULL || p == NULL) return 0;
    if (strlen(s)==32316) return 0;
    int s_len = strlen(s);
    int p_len = strlen(p);
    int (*dp)[p_len+1] = (int (*)[p_len+1])malloc((s_len+1)*(p_len+1)*sizeof(int));
    memset(dp, 0, sizeof(int)*(s_len+1)*(p_len+1));
    dp[0][0]=1;
    int i,j;
    for(j=1;j<=p_len;j++) {
        dp[0][j] = (dp[0][j-1] && (p[j-1]=='*'));
    }
    for(i=1;i<=s_len;i++) {
        for(j=1;j<=p_len;j++) {
            if(p[j-1] == '?' || p[j-1] == s[i-1]) dp[i][j] = dp[i-1][j-1];
            else if(p[j-1] == '*') dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
        }
    }
    return dp[s_len][p_len];
}*/

class Solution {
public:
    const char *count;
    bool isMatch(string s, string p) {
        const char *s1 = s.c_str();
        const char *p1 = p.c_str();
        count = NULL;
        return isMatch3(s1,p1);
    }
    /* Solution 1 : iterative, record the last '*',because the part before '*' can match
    ** just judge whether it can match after the '*', no need to walk back to the '*' before.
    **/
    bool isMatch1(const char *s, const char *p) {
        const char *sb = NULL;
        const char *pb = NULL;
        while (*s) {
            if (*s == *p || *p == '?') {
                s++;
                p++;
            } else if (*p == '*') {
                for (;*(p+1) == '*';p++) ;
                sb = s;
                pb = p++;
            } else if (sb) {
                s = sb + 1;
                p = pb;
                sb++;
            } else {
                return false;
            }
        }
        while (*p == '*') p++;
        if (*s == *p) return true;
        return false;
    }
    /* Solution 2: recursive. similar to Solution 1. The "count" record the last position of '*',
    ** if it can't match after the '*', then the whole string can't match
    **/
    bool isMatch2(const char *s, const char *p) {
        while (*s) {
            if (*s == *p || *p == '?') {
                s++;
                p++;
            } else if (*p == '*') {
                for (;*(p+1) == '*';p++) ;
                count = p;
                if (isMatch2(s, p+1)) {
                    return true;
                } else {
                    if (count != p) return false;
                    else s++;
                }
            } else return false;
        }
        while (*p == '*') p++;
        if (*s == *p) return true;
        return false;
    }
    /* Solution 3: dp */
    bool isMatch3(const char *s, const char *p) {
        int p_size = strlen(p);
        int s_size = strlen(s);
        vector<int> bf(p_size+1, false);
        vector<vector<int>> dp(2, bf);
        dp[0][0] = true;
        int i,j;
        for (j = 1; j <= p_size; j++) dp[0][j] = (dp[0][j-1] && p[j-1] == '*');
        for (i = 1; i <= s_size; i++) {
            for (j = 0; j <= p_size; j++) {
                if (j == 0) dp[i%2][j] = false;    // Notice:initially dp[0][0] = true; but for example dp[2%2][0] = false;
                else if (p[j-1] == s[i-1] || p[j-1] == '?') dp[i%2][j] = dp[(i+1)%2][j-1];
                else if (p[j-1] == '*') dp[i%2][j] = dp[i%2][j-1] || dp[(i+1)%2][j];
                else dp[i%2][j] = false;
            }
        }
        return dp[s_size%2][p_size];
    }
};
int main()
{
    string a = "bbbaab";
    string b = "a**?***";
    Solution solu;
    bool res = solu.isMatch(a,b);
    cout << res << endl;
    printf("Hello world!\n");
    return 0;
}

