#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /** Solution : use the first row and the first col recording the (n-1)X(n-1) matrix;
    ** use first_row and first_col recording the first row and the first col
    **/
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) return;
        int col = matrix[0].size();
        int i,j;
        int first_row = 0;
        int first_col = 0;
        for(i = 0; i < col; i++) {
            if (matrix[0][i] == 0) {
                first_row = 1;
                break;
            }
        }
        for (i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                first_col = 1;
                break;
            }
        }
        for (i = 1; i < row; i++) {
            for (j = 1; j < col; j++) {
                if (matrix[i][j] == 0) matrix[i][0]=matrix[0][j]=0;
            }
        }
        for(i=1;i<row;i++) {
            if (matrix[i][0] == 0) {
                for (j = 0; j < col; j++) matrix[i][j] = 0;
            }
        }
        for(j=1; j < col; j++) {
            if (matrix[0][j] == 0) {
                for(i = 0; i < row; i++) matrix[i][j] = 0;
            }
        }
        if (first_row) {
            for(j = 0; j < col; j++) matrix[0][j] = 0;
        }
        if (first_col) {
            for(i=0;i < row; i++) matrix[i][0] = 0;
        }
    }
};
int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(0);
    vector<vector<int>> matrix;
    matrix.push_back(a);
    Solution solu;
    solu.setZeroes(matrix);
    cout << "Hello world!" << endl;
    return 0;
}
