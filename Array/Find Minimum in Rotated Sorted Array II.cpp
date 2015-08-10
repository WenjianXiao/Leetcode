#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty()) return 0;
        int size = num.size();
        int left = 0;
        int right = size - 1;
        while (left < right && num[left] >= num[right]) {
            int mid = (left + right) / 2;
            if (num[mid] > num[right]) {
                left = mid + 1;
            } else if (num[mid] < num[left]) {
                right = mid;
            } else {
                ++left;  /** this case : num[left] == num[right],but you can't shorten the scale, so left++ or right--*/
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
