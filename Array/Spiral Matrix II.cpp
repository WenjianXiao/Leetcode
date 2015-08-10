#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int rmin = 0, rmax = n - 1;
        int cmin = 0, cmax = n - 1;
        int cnt = 1;
        while (true) {
            int idx;
            for (idx = cmin; idx <= cmax; idx++) matrix[rmin][idx] = cnt++;
            if (++rmin > rmax) break;
            for (idx = rmin; idx <= rmax; idx++) matrix[idx][cmax] = cnt++;
            if (cmin > --cmax) break;
            for (idx = cmax; idx >= cmin; idx--) matrix[rmax][idx] = cnt++;
            if (rmin > --rmax) break;
            for (idx = rmax; idx >= rmin; idx--) matrix[idx][cmin] = cnt++;
            if (++cmin > cmax) break;
        }
        return matrix;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
