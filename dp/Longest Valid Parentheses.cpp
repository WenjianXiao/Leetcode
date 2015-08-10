#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        return longestValidParentheses1(s);
    }
    /** Solution 1 : 用栈记录匹配‘(’的索引,当‘）’到来时，只需将栈pop(),如果此时栈不为空，说明能匹配上，
    ** 此时的匹配长度就是用当前idx - 前一个未匹配的位置。如果此时栈为空，说明没有可匹配的，此时这个位置将作为
    ** 匹配的前一个位置，将它压入栈中
    **/
    int longestValidParentheses1(string s) {
        int len = s.size();
        if (len == 0) return 0;
        stack<int> stk;
        stk.push(-1);
        int idx,ans=0;
        for(idx = 0; idx < len; idx++) {
            if (s[idx] == '(') {
                stk.push(idx);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    int dis = idx - stk.top();
                    if (dis > ans) ans = dis;
                } else {
                    stk.push(idx);
                }
            }
        }
        return ans;
    }
    /** Solution 2 : push the length of last valid parentheses into stack.*/
    int longestValidParentheses2(string s) {
        stack<int> stk;
        int cnt = 0, ans = 0;
        int s_size = s.size();
        int i;
        for (i = 0; i < s_size; i++) {
            if (s[i] == '(') {
                stk.push(cnt);
                cnt = 0;
            } else if (!stk.empty()) {
                cnt += (1+stk.top());
                stk.pop();
                ans = max(ans, cnt);
            } else cnt = 0;
        }
        return ans;
    }
    /** Solution 3 : Traverse the string twice, taking O(n) time.
    ** First time, mark all the matching parentheses as '*' (push the index of '(' into <stack>).
    ** Second time, count the longest consecutive '*'.
    */
    int longestValidParentheses3(string s) {
        stack<int> stk;
        int s_size = s.size();
        int i;
        for (i = 0; i < s_size; i++) {
            if (s[i] == '(') stk.push(i);
            else if (!stk.empty()) {
                s[i] = '*';
                s[stk.top()] = '*';
                stk.pop();
            }
        }
        int cnt = 0, ans = 0;
        for (i = 0; i < s_size; i++) {
            if (s[i] == '*') cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
    /** Solution 4: dp[i]: i is the first index of possible result,dp[i] is the length;*/
    int longestValidParentheses4(string s) {
        int s_size = s.size();
        if (s_size <= 1) return 0;
        vector<int> dp(s_size, 0);
        dp[s_size - 1] = 0;
        int i,ans = 0;
        for (i = s_size - 2; i >= 0; i--) {
            int match = i + dp[i+1] + 1;
            if (match < s_size && s[i] == '(' && s[match] == ')') {
                dp[i] = dp[i+1] + 2;
                if (match + 1 < s_size) dp[i] += dp[match + 1];
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
    /** Solution 5 :  O(1) Space, and Traverse the string twice, taking O(n) time.
    ** 正向和反向遍历，正向就是')'过多的情况，反向就是'('过多的情况。
    **/
    int longestValidParentheses5(string s) {
        int s_size = s.size();
        int i,cnt=0,val=0,ans=0;
        for (i = 0; i < s_size; i++) {
            cnt += (s[i] == '(' ? 1 : -1);
            if (cnt < 0) {
                cnt = val = 0;
                continue;
            }
            val += (s[i] == ')' ? 2 : 0);
            ans = (cnt == 0 ? max(ans, val) : ans);
        }
        cnt = 0,val;
        for (i = s_size - 1; i >= 0; i--) {
            cnt += (s[i] == ')' ? 1 : -1);
            if (cnt < 0) {
                cnt = val = 0;
                continue;
            }
            val += (s[i] == '(' ? 2 : 0);
            ans = (cnt == 0 ? max(ans, val) : ans);
        }
        return ans;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
