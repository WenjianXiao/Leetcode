#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<bool>> visited;
    bool exist(vector<vector<char>>& board, string word) {
        int w_size = word.length();
        if (w_size == 0) return true;
        int r_num = board.size();
        if (r_num == 0) return false;
        int c_num = board[0].size();
        int i,j;
        vector<bool> tmp(c_num,false);
        vector<vector<bool>> tmp1(r_num, tmp);
        visited = tmp1;
        for(i = 0; i < r_num; i++) {
            for(j = 0; j < c_num; j++) {
                if (dfs(board, word, i, j, w_size, 0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> & board, string word, int x, int y, int w_size, int num) {
        if (board[x][y] == word[num]) {
            if (num == w_size - 1) return true;
            int i;
            int r_num = board.size();
            int c_num = board[0].size();
            visited[x][y]=true;
            for (i = 0; i < 4; i++) {
                int x1 = x+dir[i][0];
                int y1 = y+dir[i][1];
                if (x1 >= r_num || x1 < 0 || y1 >= c_num || y1 < 0) continue;
                if (visited[x1][y1]) continue;
                if (dfs(board, word, x1,y1,w_size,num+1)) return true;
            }
            visited[x][y]= false;
            return false;
        } else return false;
    }
};
int main()
{
    vector<char> tmp(1,'a');
    vector<vector<char>> b(1,tmp);
    Solution solu;
    string word = "ab";
    bool res = solu.exist(b,word);
    cout << res <<endl;
    cout << "Hello world!" << endl;
    return 0;
}
