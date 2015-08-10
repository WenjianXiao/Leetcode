#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <unordered_set>
#include <stdlib.h>
#include <algorithm>
#include <map>
using namespace std;
//good solution: http://www.cnblogs.com/easonliu/p/3680966.html
class Solution {
public:
    vector<string> solu2;
    string s2;
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        return wordBreak2(s,wordDict);
    }
    /*Solution 1*/
    vector<string> wordBreak1(string s, unordered_set<string>& wordDict) {
        int s_len = s.size();
        vector<string> res;
        if (s_len == 0) return res;
        int i,l,j;
        vector<int> serial;
        serial.clear();
        vector<vector<int>> lv(s_len+1,serial);
        vector<vector<vector<int>> > record(s_len,lv);
        for (l = 1; l <= s_len; l++) {
            for (i = 0; i <= s_len - l; i++) {
                if (wordDict.find(s.substr(i,l)) != wordDict.end()) {
                    record[i][l].push_back(0);
                }
                for (j = 1; j < l; j++) {
                    if (record[i][j].size() != 0 && record[i+j][l-j].size() != 0)
                        record[i][l].push_back(j);
                }
            }
        }
        res=print_string1(record,s,0,wordDict);
        return res;
    }
    vector<string> print_string1(vector<vector<vector<int>>> &record,string s,int s_pos,unordered_set<string>& wordDict) {
        int l = s.size();
        vector<string> sep_s;
        if (l == 0) return sep_s;
        vector<int> sep = record[s_pos][l];
        int sep_num = sep.size();
        int i;
        for (i = 0; i < sep_num; i++) {
            if (sep[i] == 0) {
                sep_s.push_back(s);
                continue;
            }
            string pre = s.substr(0,sep[i]);
            if (wordDict.find(pre) == wordDict.end()) continue;   //this is important;
            vector<string> s2 = print_string1(record, s.substr(sep[i],l-sep[i]),s_pos+sep[i],wordDict);
            int s2_len = s2.size();
            int i;
            for(i=0; i < s2_len; i++)
            {
                string s = pre+" " + s2[i];
                sep_s.push_back(s);
            }
        }
        return sep_s;
    }
    /*Solution 2: simplifiy the Solution 1 */
     vector<string> wordBreak2(string s, unordered_set<string>& wordDict) {
         solu2.clear();
         int len = s.size();
         if (len == 0) return solu2;
         int i,j;
         vector<bool> dp(len+1,false);
         dp[0] = true;
         for (i=1;i<=len;i++) {
            for(j=0;j<i;j++) {
                if (dp[j] && wordDict.find(s.substr(j,i-j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
         }
         print_string2(s, dp, len, wordDict);
         return solu2;
     }
     void print_string2(string s, vector<bool>& dp, int len, unordered_set<string>& dict) {
        int i;
        int s_size = s.size();
        if (s_size == 0) {
            solu2.push_back(s2);
            return;
        }
        for (i = 0; i < s_size; i++) {
            if (dp[i] && dict.find(s.substr(i,len-i)) != dict.end()) {
                string tmp = s2;
                if (s2.size() == 0) s2 = s.substr(i,len-i);
                else s2 = s.substr(i,len-i) + " " + s2;
                print_string2(s.substr(0,i), dp, len, dict);
                s2 = tmp;
            }
        }
     }
};
int main()
{
    Solution solu;
    string s = "catsanddog";
    unordered_set<string> wordDict;
    wordDict.insert("cat");
    wordDict.insert("cats");
    wordDict.insert("and");
    wordDict.insert("sand");
    wordDict.insert("dog");
    string a = "a";
    int i=0;
    for (i = 0; i < 100; i++) {
        wordDict.insert(a);
        a+="a";
    }
    vector<string> res = solu.wordBreak(s, wordDict);
    int res_size = res.size();
    for (i = 0; i < res_size; i++) cout << res[i] << endl;
    cout << "Hello world!" << endl;
    return 0;
}
