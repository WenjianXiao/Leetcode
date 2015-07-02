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
    /*Solution 2: ����range[m,n],�����������һλ����0,1֮�䲻�Ͻ����
    ** ���m != n��˵���϶���0,1ͬʱ���ڣ�And֮����ô���һ��϶�Ϊ0��
    ** ��m >>= 1, n >>= 1֮�����m != n��˵�����һλ�϶���0,1֮��Ĺ���
    ** ��ôAnd֮����λ�϶�Ϊ0.*/
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
