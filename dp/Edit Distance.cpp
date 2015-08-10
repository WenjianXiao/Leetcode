#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        if (size1 == 0) return size2;
        if (size2 == 0) return size1;
        vector<vector<int>> dp(2, vector<int>(size2+1,0));
        int i,j;
        for(i = 0; i <= size1; i++) {
            dp[i%2][0] = i;
            for(j = 1; j <= size2; j++) {
                if (i == 0) dp[i][j] = j;
                else {
                    dp[i%2][j] = min(min(dp[i%2][j-1],dp[(i+1)%2][j]),dp[(i+1)%2][j-1])+1;
                    if (word1[i-1] == word2[j-1]) dp[i%2][j] = min(dp[i%2][j], dp[(i+1)%2][j-1]);
                }
            }
        }
        return dp[size1%2][size2];
    }
};
int main()
{
    Solution solu;
    string s1="acdcfg";
    string s2 = "abdcf";
    int res = solu.minDistance(s1,s2);
    cout <<"res: " << res << endl;
    cout << "Hello world!" << endl;
    return 0;
}
