#include <iostream>
#include <set>
#include <cstring>
#include <unordered_set>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        return wordBreak2(s,wordDict);
    }
    /*Solution : dp[i][l] = (dp[i][l] || dp[i][k]&&dp[i+k][l-k]) (k->1...l-1);
    **dp[i][l] : the substr of length l and start position i is separated?
    */
    bool wordBreak1(string s, unordered_set<string>& wordDict) {
        int s_len = s.size();
        if (s_len == 0) return true;
        int dict_size = wordDict.size();
        int i,l,j;
        bool (*dp)[s_len+1] = (bool (*)[s_len+1])malloc(s_len*(s_len+1)*sizeof(bool));
        memset(dp, false, s_len*(s_len+1)*sizeof(bool));
        for (l = 1; l <= s_len; l++) {
            for (i = 0; i <= s_len - l; i++) {
                dp[i][l] = (wordDict.find(s.substr(i,l)) != wordDict.end());
                if (dp[i][l]) continue;
                for (j = 1; j < l; j++) {
                    dp[i][l] = (dp[i][l] || (dp[i][j]&&dp[i+j][l-j]));
                    if (dp[i][l]) break;
                }
            }
        }
        return dp[0][s_len];
    }
    bool wordBreak2(string s, unordered_set<string>& wordDict) {
        int s_size = s.size();
        if (s_size == 0) return true;
        vector<bool> dp(s_size+1, false);
        dp[0] = true;
        int i,j;
        for (i = 1; i <= s_size; i++) {
            for (j = 0; j < i; j++) {
                if (dp[j] && wordDict.find(s.substr(j,i-j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s_size];
    }
};
int main()
{
    string s = "a";
    unordered_set<string> wordDict;
    Solution solu;
    solu.wordBreak(s,wordDict);
    cout << "Hello world!" << endl;
    return 0;
}
