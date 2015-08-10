#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans=1;
        int i=1;
        int tmp = (m>n?n:m);
        for(i=1;i<=tmp-1;i++) {
            ans = ans*(m+n-1-i)/i;
        }
        return ans;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
