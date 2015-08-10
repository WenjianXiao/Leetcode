#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        res.clear();
        int i,j;
        int num_size = num.size();
        sort(num.begin(), num.end());
        for (i = 0; i < num_size - 3; i++) {
            if (i != 0 && num[i] == num[i-1]) continue;
            for (j = i+1; j < num_size - 2; j++) {
                if (j != i+1 && num[j] == num[j-1]) continue;
                int left = j+1;
                int right = num_size - 1;
                while (left < right) {
                    LL sum = num[i] + num[j] + num[left] + num[right];
                    if (sum < target) left++;
                    else if (sum > target) right--;
                    else {
                        vector<int> entry;
                        entry.clear();
                        entry.push_back(num[i]);
                        entry.push_back(num[j]);
                        entry.push_back(num[left]);
                        entry.push_back(num[right]);
                        res.push_back(entry);
                        while(left < right && num[left+1] == num[left]) left++;
                        while(left < right && num[right-1] == num[right]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> num;
    num.clear();
    num.push_back(1);
    num.push_back(0);
    num.push_back(-1);
    num.push_back(0);
    num.push_back(-2);
    num.push_back(2);
    Solution s;
    vector<vector<int> > res;
    res = s.fourSum(num,0);
    printf("res_size:%d\n", res.size());
    int i,j;
    for(i = 0; i < res.size(); i++) {
        for (j = 0; j < res[i].size(); j++){
            printf("%d,",res[i][j]);
        }
        printf("\n");
    }
    cout << "Hello world!" << endl;
    return 0;
}
