#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p_size = prices.size();
        if (p_size == 0) return 0;
        int g = 0,i;
        for (i = 1; i < p_size; i++) {
            if (prices[i]>prices[i-1]) g += prices[i] - prices[i-1];
        }
        return g;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
