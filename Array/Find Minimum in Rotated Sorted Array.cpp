#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty()) return 0;
        int size = num.size();
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (num[mid] > num[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return num[left];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
