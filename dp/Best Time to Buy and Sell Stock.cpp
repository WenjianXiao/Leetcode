#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    /* Solution : dp[i] = max(dp[i-1]+prices[i+1]-prices[i], prices[i+1]-prices[i]); */
    int maxProfit(vector<int>& prices) {
        int p_size = prices.size();
        if (p_size == 0) return 0;
        int l = 0;
        int g = 0;
        int i;
        for (i = 0; i < p_size-1; i++) {
            l = max(prices[i+1]-prices[i]+l, prices[i+1]-prices[i]);
            g = max(g, l);
        }
        return g;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
