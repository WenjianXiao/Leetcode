#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k == 0) return res;
        combinationSum3Helper(k,n,1);
        return res;
    }
    void combinationSum3Helper(int k, int n, int s) {
        if (k > 10 - s) return;
        if (n > k*(9+10-k)/2) return;
        if (n < k*(s+s+k-1)/2) return;
        if (k == 1) {
            tmp.push_back(n);
            res.push_back(tmp);
            tmp.pop_back();
        }
        int i;
        for(i = s; i <= 8; i++) {
            tmp.push_back(i);
            combinationSum3Helper(k-1,n-i,i+1);
            tmp.pop_back();
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
