#include <iostream>

using namespace std;
class Solution {
public:
    /*Solution 1: */
    int rangeBitwiseAnd(int m, int n) {
        int num = n - m;
        int k;
        int res=0;
        for (k = 0; k < 31; k++) {
            if ((m >> k)%2) {
                int dis = m % (1 << k);
                if (num <= (1<<k)-dis) res = (res |(1<<k));
            }
        }
        return res;
    }
    /*Solution 2: 对于range[m,n],由于它们最后一位是在0,1之间不断交替的
    ** 如果m != n，说明肯定有0,1同时存在，And之后，那么最后一面肯定为0。
    ** 将m >>= 1, n >>= 1之后，如果m != n，说明最后一位肯定有0,1之间的过度
    ** 那么And之后这位肯定为0.*/
    int rangeBitwiseAnd1(int m, int n) {
        int offset = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            offset++;
        }
        return m << offset;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
