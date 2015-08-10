#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int i;
        long long ans = 1;
        for (i = 0; i < n; i++) ans = ans*(2*n-i)/(i+1);
        ans /= (n+1);
        return ans;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
