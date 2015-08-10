#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        return calculateMinimumHP1(dungeon);
    }
    /** Solution 1 : dp[i][j] : �ڵ���(i,j)���֮ǰ���뱣֤����СѪ����
    ** Ϊʲô����dp[i][j]��Ϊ����(i,j)����СѪ���أ�dp[i][j] --> dp[i][j+1]�޷��������Ϊ����СѪ���Ĺ��̲�û��
    **��������·�̵������������������������dp[i][j+1]�϶��Ǳ�ʵ�ʵĴ�
    **ͬʱ���뱣֤dp[i][j]���ڵ���0�����磨-3,5��,��Ȼ�����ֵ��ʵ�ʵ�С��
    **/
    int calculateMinimumHP1(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        if (r == 0) return 1;
        int c = dungeon[0].size();
        if (c == 0) return 1;
        int i,j;
        vector<int> dp(c);
        for (i = r - 1; i >= 0; i--) {
            for (j = c - 1; j >= 0; j--) {
                if (i == r - 1 && j == c - 1) dp[j] = max(-dungeon[i][j],0);
                else if (i == r - 1) dp[j] = max(dp[j+1] - dungeon[i][j],0);
                else if (j == c - 1) dp[j] = max(dp[j] - dungeon[i][j],0);
                else {
                    dp[j] = max(min(dp[j+1],dp[j]) - dungeon[i][j],0);
                }
            }
        }
        return dp[0]+1;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
