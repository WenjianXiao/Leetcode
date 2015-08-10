#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0) return false;
        int col = matrix[0].size();
        if (col == 0) return false;
        int left = 0;
        int right = row*col - 1;
        while (left <= right) {
            int mid = (left+right)/2;
            int x = mid/col;
            int y = mid - x*col;
            if (matrix[x][y] < target) left = mid + 1;
            else if (matrix[x][y] > target) right = mid - 1;
            else return true;
        }
        return false;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
