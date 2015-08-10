#include <iostream>

using namespace std;
class Solution {
public:
    uint32_t reverseBits1(uint32_t n) {
        int res=0;
        int times=32;
        while(times--) {
            res=(res<<1) + n%2;
            n >>=1;
        }
        return res;
    }
    uint32_t reverseBits2(uint32_t n) {
        int m1 = 0x55555555;
        int m2 = 0x33333333;
        int m4 = 0x0f0f0f0f;
        int m8 = 0x00ff00ff;
        int m16 = 0x0000ffff;
        n = ((n&m1)<<1) | ((n>>1)&m1);
        n = ((n&m2)<<2) | ((n>>2)&m2);
        n = ((n&m4)<<4) | ((n>>4)&m4);
        n = ((n&m8)<<8) | ((n>>8)&m8);
        n = ((n&m16)<<16) | ((n>>16)&m16);
        return n;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
