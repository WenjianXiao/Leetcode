#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        merge_1(nums1, m, nums2, n);
    }
    /** Solution 1 **/
    void merge_1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,j;
        for (i = m-1; i >=0; i--) {
            nums1[i+n] = nums1[i];
        }
        int k=0;
        for (i=n,j=0; i < n+m && j < n;k++) {
            if (nums1[i] < nums2[j]) {
                nums1[k] = nums1[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
        }
        while(i < n+m) {
            nums1[k++] = nums1[i++];
        }
        while (j < n) {
            nums1[k++] = nums2[j++];
        }
    }
    /** Solution 2 **/
    void merge_2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, x = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) nums1[x--] = nums1[i--];
            else nums1[x--] = nums2[j--];
        }
        while (j >= 0) nums1[x--] = nums2[j--];
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
