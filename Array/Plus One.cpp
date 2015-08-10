#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        res.clear();
        int d_size = digits.size();
        int i;
        int c = 1;
        for(i = d_size - 1; i>=0; i--) {
            int num = (digits[i] + c)%10;
            c = (digits[i] + c)/10;
            res.push_back(num);
        }
        if (c>0) res.push_back(c);
        reverse(res.begin(),res.end());
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
