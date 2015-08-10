#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScramble1(s1,s2);
    }
    /* Solution 1 : dp[len][i][j] : len is the length ,i is the start index of s1, j is the start index of s2
    ** seperate the string s1 to AB, and s2 to CD;
    ** So there is 2 cases : A<==>C && B<==>D; A<==>D && B<==>C;
    ** so it's easy to get the state transition equation.
    **/
    bool isScramble1(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 != len2) return false;
        if (len1 == 0) return true;
        bool (*dp)[len1][len1] = (bool (*)[len1][len1])malloc(len1*len1*len1*sizeof(bool));
        int i,j;
        memset(dp, false, sizeof(bool)*len1*len1*len1);
        for(i = 0; i < len1; i++) {
            for(j = 0; j < len2; j++) {
                dp[0][i][j] = (s1[i] == s2[j]);
            }
        }
        int k,m;
        for(k=1;k<len1;k++) {
            for(i=0;i<len1-k;i++) {
                for(j=0;j<len2-k;j++) {
                    for(m=0;m<k;m++) {
                        dp[k][i][j] = ((dp[m][i][j] && dp[k-m-1][i+m+1][j+m+1]) ||
                                       (dp[m][i][j+k-m] && dp[k-m-1][i+m+1][j]));
                        if (dp[k][i][j]) break;
                    }
                }
            }
        }
        return dp[len1-1][0][0];
    }
};
int main()
{
    Solution solu;
    string s1="abc";
    string s2="bca";
    bool res = solu.isScramble(s1,s2);
    cout << res << endl;
    cout << "Hello world!" << endl;
    return 0;
}
