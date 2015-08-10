#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        return spiralOrder_1(matrix);
    }
    /** Solution 1 : simulate the process **/
    vector<int> spiralOrder_1(vector<vector<int> >& matrix) {
        vector<int> order;
        int r_num = matrix.size();
        if (r_num == 0) return order;
        int c_num = matrix[0].size();
        int total_num = r_num*c_num;
        int r_step = c_num - 1;
        int c_step = r_num - 1;
        int r_step_idx = r_step;
        int c_step_idx = c_step;
        int i,row_no=0,col_no=0;
        int dir_idx = 0;
        for (i = 0; i < total_num ; i++) {
            order.push_back(matrix[row_no][col_no]);
            if (i == total_num -1) break;
            if (c_step_idx == 0 && (dir_idx%2)) {
                dir_idx = (dir_idx+1)%4;
                c_step_idx = --c_step;
            }
            if (r_step_idx == 0 && (dir_idx%2 == 0)) {
                dir_idx = (dir_idx+1)%4;
                if (i == c_num-1) r_step_idx = r_step;
                else r_step_idx = --r_step;
            }
            row_no = row_no + dir[dir_idx][0];
            col_no = col_no + dir[dir_idx][1];
            if (dir_idx % 2) c_step_idx--;
            else r_step_idx--;
        }
        return order;
    }
    /** Solution 2: Simplify the Solution 1 **/
    vector<int> spiralOrder_2(vector<vector<int> >& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int rmin = 0, rmax = matrix.size() - 1;
        int cmin = 0, cmax = matrix[0].size() - 1;
        while (true) {
            int idx;
            for (idx = cmin; idx <= cmax; idx++) res.push_back(matrix[rmin][idx]);
            if (++rmin > rmax) break;
            for (idx = rmin; idx <= rmax; idx++) res.push_back(matrix[idx][cmax]);
            if (cmin > --cmax) break;
            for (idx = cmax; idx >= cmin; idx--) res.push_back(matrix[rmax][idx]);
            if (rmin > --rmax) break;
            for (idx = rmax; idx >= rmin; idx--) res.push_back(matrix[idx][cmin]);
            if (++cmin > cmax) break;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int> > matrix;
    int i,j;
    int row=3,col=4;
    int cnt = 1;
    for(i=0;i<row;i++) {
        vector<int> tmp;
        tmp.clear();
        for(j = 0; j<col;j++) {
            tmp.push_back(cnt++);
        }
        matrix.push_back(tmp);
    }
    vector<int> res = s.spiralOrder(matrix);
    for(i=0;i<res.size();i++) {
        cout << res[i] << " ";
    }
    cout <<endl;
    cout << "Hello world!" << endl;
    return 0;
}
