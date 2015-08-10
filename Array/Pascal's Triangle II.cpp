#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        return getRow_1(rowIndex);
    }
    vector<int> getRow_1(int rowIndex) {
        vector<int> row;
        row.clear();
        int i;
        for (i = 0; i <= rowIndex; i++) {
            row.push_back(Cn(rowIndex, i));
        }
        return row;
    }
    int Cn(int n, int k) {
        if (n == 0 || n == k) return 1;

        int i;
        unsigned long long res=1;
        for (i = 1; i<=n-k; i++) {
            res = res*(n-i+1)/i;
        }
        return res;
    }
    vector<int> getRow_2(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        int i,j;
        for (i = 1; i <= rowIndex; ++i)
            for (j = i-1; j >= 1; --j)
                res[j] += res[j-1];
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
