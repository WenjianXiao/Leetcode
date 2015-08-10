#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        largestRectangleArea1(height);
    }
    /* Solution 1 */
    int largestRectangleArea1(vector<int>& height) {
        stack<int> st;
        while(!st.empty()) st.pop();
        int h_size = height.size();
        int i;
        int max_area = 0;
        st.push(-1);
        for(i = 0; i < h_size; i++) {
            if (st.top() == -1) st.push(i);
            else {
                int top_val;
                while (st.top()!=-1) {
                   top_val = height[st.top()];
                   if (height[i] < top_val) {
                        st.pop();
                        max_area = max(max_area, top_val*(i-st.top()-1));
                   } else {
                        st.push(i);
                        break;
                   }
                }
                if (st.top() == -1) st.push(i);
            }
        }
        while (st.top()!=-1) {
            int top_val = height[st.top()];
            st.pop();
            max_area = max(max_area, top_val*(h_size - st.top()-1));
        }
        return max_area;
    }

    /* Solution 2 : Simplify the code of Solution 1*/
    int largestRectangleArea2(vector<int>& height) {
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
};
int main()
{
    vector<int> height;
    height.push_back(2);
    height.push_back(0);
    height.push_back(2);
    Solution solu;
    int res = solu.largestRectangleArea(height);
    cout << "res :" << res << endl;
    cout << "Hello world!" << endl;
    return 0;
}
