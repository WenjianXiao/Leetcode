#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > tri(numRows);
        if (numRows == 0) return tri;
        tri[0].push_back(1);
        int i,j;
        for (i = 1; i < numRows; i++) {
            tri[i].push_back(1);
            for (j = 1; j < i; j++) tri[i].push_back(tri[i-1][j-1] + tri[i-1][j]);
            tri[i].push_back(1);
        }
        return tri;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
