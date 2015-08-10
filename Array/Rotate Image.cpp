#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        return rotate_1(matrix);
    }
    /** Solution 1: initially transfer (i,j) ---> (j, n-i-1);
    ** we transfer it to (i,j)--->(j,i)---->(j,n-i-1);
    **/
    void rotate_1(vector<vector<int>>& matrix) {
        int i,j;
        int matrixRowSize = matrix.size();
        int matrixColSize = matrixRowSize;
        for (i = 0; i < matrixRowSize; i++)
            for (j = i; j < matrixColSize; j++)
                swap(matrix[i][j],matrix[j][i]);
        for (i = 0; i < matrixRowSize; i++)
            for (j = 0; j < matrixColSize/2; j++)
                swap(matrix[i][j], matrix[i][matrixColSize-1-j]);

    }
    /** Solution 2: divide the matrix to four parts
    ** initially (i,j)-->(j,n-i)-->(n-i,n-j)-->(n-j,i)-->(i,j)
    ** the transfer change to the four parts's transfer
    ** NOTICE:when n is odd, i < (n+1)/2, for example n = 3;
    **/
    void rotate_2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++)
            for (int j = 0; j < n / 2; j++)
                rotateElement(matrix, i, j);
    }
    /** Solution 3: divide the matrix to n/2 level, transfer every level
    ** as required.
    **/
    void rotate_3(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
            for (int j = i; j < n - i - 1; j++)
                rotateElement(matrix, i, j);
    }
    /** (n-j,i)-->(i,j)-->(j,n-i)-->(n-i,n-j) **/
    void rotateElement(vector<vector<int> > &matrix, int row, int col)
    {
        int temp = matrix[row][col];
        for (int i = 0; i < 3; i++)
        {
            int c = row;
            int r = matrix.size() - 1 - col;
            matrix[row][col] = matrix[r][c];
            row = r;
            col = c;
        }
        matrix[row][col] = temp;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
