#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rnum = matrix.size();
        if (rnum == 0) return 0;
        int cnum = matrix[0].size();
        if (cnum == 0) return 0;
        int i,j;
        int max_val = 0;
        int (*dp)[cnum] = (int (*)[cnum])malloc(2*cnum*sizeof(int));
        for (i = 0; i < rnum; i++) {
            for (j = 0; j < cnum; j++) {
                if (i == 0 || j == 0) dp[i%2][j] = (matrix[i][j] == '1');
                else if (matrix[i][j] == '0') dp[i%2][j] = 0;
                else {
                    dp[i%2][j] = min(dp[(i+1)%2][j-1],min(dp[i%2][j-1],dp[(i+1)%2][j])) + 1;
                }
                if (dp[i%2][j] > max_val) max_val = dp[i%2][j];
            }
        }
        return max_val*max_val;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
