#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int h_s = height.size();
        int max_area = 0;
        int i=0;
        stack<int> s;
        while(i < h_s) {
            if (s.empty() || height[i] >= height[s.top()]) {
                s.push(i++);
            } else {
                int top_h = height[s.top()];
                s.pop();
                max_area = max(max_area, top_h*(s.empty()? i : (i-s.top()-1)));
            }
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r_num = matrix.size();
        if (r_num == 0) return 0;
        int c_num = matrix[0].size();
        if (c_num == 0) return 0;
        int i,j,max_area = 0;
        vector<int> dp(c_num,0);
        for(i = 0; i < r_num; i++) {
            for(j = 0; j < c_num; j++) {
                if (i == 0) dp[j] = matrix[i][j]-'0';
                else {
                    if (matrix[i][j] == '1') dp[j] = dp[j] + 1;
                    else dp[j] = 0;
                }
            }
            max_area = max(max_area, largestRectangleArea(dp));
        }
        return max_area;
    }
};
int main()
{
    vector<char> tmp(1,'1');
    vector<vector<char>> matrix;
    matrix.push_back(tmp);
    Solution solu;
    int res = solu.maximalRectangle(matrix);
    cout << "res :" << res << endl;
    cout << "Hello world!" << endl;
    return 0;
}
