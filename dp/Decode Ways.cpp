#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int dp[3];
        int s_size = s.length();
        if (s_size == 0) return 0;
        dp[0] = 1;
        if (s[0]!='0')
            dp[1] = 1;
        else return 0;
        int i;
        for(i=2;i<=s_size;i++) {
            int val = (s[i-2] - '0')*10 + s[i-1] - '0';
            if (val == 0) return 0;
            else if(s[i-2] == '0') dp[i%3] = dp[(i+2)%3];
            else if (s[i-1] == '0' && s[i-2] <= '2') dp[i%3] = dp[(i+1)%3];
            else if (s[i-1] == '0') return 0;
            else if (val > 26) dp[i%3] = dp[(i+2)%3];
            else dp[i%3]=dp[(i+1)%3] + dp[(i+2)%3];
        }
        return dp[s_size%3];
    }
};
int main()
{
    Solution solu;
    string s = "10";
    int res = solu.numDecodings(s);
    cout <<"res:"<< res<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
