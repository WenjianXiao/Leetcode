#include <iostream>

using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) return 0;
        if (k >= prices.size()/2) return solveMaxProfit(prices);
        vector<int> g(k+1,0);
        vector<int> l(k+1,0);
        /* l[i][j] = max(l[i-1][j] + diff, g[i-1][j-1]+diff);
        ** g[i][j] = max(g[i-1][j],l[i][j]);
        ** l[i][j] : i days ,j transactions and must have a trasaction at the jth day;
        ** g[i][j] : i days, j trans;
        ** l[i][j], when the last buy before i-1 , l[i][j]->l[i-1][j] + diff; when the last buy at i-1, g[i-1][j-1] + diff;

        ** simplify -> l[j] = max(g[j - 1] + diff, l[j] + diff); g[j] = max(g[j], l[j]);
        ** NOTICE : the j must change from k->1,because l[j] use the g[j-1],the g[j-1] is g[i-1][j-1].l[j] -> l[i-1][j]
        ** g[j] -> g[i-1][j]
        */
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; --j) {
                l[j] = max(g[j - 1] + diff, l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
    int solveMaxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
