#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <map>
#include <cstring>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int s_len = s.length();
        unordered_map<int,int> mp;
        vector<string> res;
        int convert[26];
        if (s_len < 10) return res;
        convert[0]=0;
        convert['C'-'A'] = 1;
        convert['G'-'A'] = 2;
        convert['T'-'A'] = 3;
        int i,hvalue=0;
        for (i = 0; i < 10 && i < s_len; i++) {
            hvalue <<= 2;
            hvalue |= convert[s[i]-'A'];
        }
        mp[hvalue]++;
        for (i=10; i < s_len; i++) {
            hvalue <<= 2;
            hvalue |= convert[s[i]-'A'];
            hvalue &= 0x000fffff;
            if (mp[hvalue] == 1) {
                res.push_back(s.substr(i-9,10));
            }
            mp[hvalue]++;
        }
        return res;
    }
};

int main()
{

}
