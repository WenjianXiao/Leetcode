#include <iostream>

using namespace std;
/*Solution 1*/
int hammingWeight(uint32_t n) {
    int count=0;
    while (n) {
        if (n%2) count++;
        n = n >> 1;
    }
    return count;
}
/*Solution 2*/
int hammingWeight2(uint32_t n) {
    int count;
    for(count=0;n;count++) {
        n &= n-1;
    }
    return count;
}
/*Solution 3*/
int hammingWeight3(uint32_t n) {
    int m1 = 0x55555555;
    int m2 = 0x33333333;
    int m4 = 0x0f0f0f0f;
    int m8 = 0x00ff00ff;
    int m16 = 0x0000ffff;
    int count = n;
    count = (count&m1) + ((count>>1)&m1);
    count = (count&m2) + ((count>>2)&m2);
    count = (count&m4) + ((count>>4)&m4);
    count = (count&m8) + ((count>>8)&m8);
    count = (count&m16) + ((count>>16)&m16);
}
/*Solution 4*/
int hammingWeight4(uint32_t n) {
    return __builtin_popcount(n);
}

int main()
{
    int count = __builtin_popcount(32);
    cout << count << endl;
    return 0;
}
