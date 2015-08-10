#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return findMedianSortedArrays1(nums1, nums2);
    }
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if ((m+n) & 1) return findKthSortedArrays1(nums1.begin(),m,nums2.begin(),n,(m+n)/2);
        else return (findKthSortedArrays1(nums1.begin(),m,nums2.begin(),n,(m+n)/2-1) +
                    findKthSortedArrays1(nums1.begin(),m,nums2.begin(),n,(m+n)/2)) / 2;
    }
    double findKthSortedArrays1(vector<int>::iterator it1, int m, vector<int>::iterator it2, int n, int k) {
        if (m == 0) return *(it2+k);
        if (n == 0) return *(it1+k);
        int x = m/2, y = n/2;
        if (*(it1+x) > *(it2+y)) {
            if (k < x+y+1) return findKthSortedArrays1(it1, x, it2, n, k);
            else return findKthSortedArrays1(it1,m,it2+y+1,n-y-1,k-y-1);
        } else {
            if (k < x+y+1) return findKthSortedArrays1(it1,m,it2,y,k);
            else return findKthSortedArrays1(it1+x+1, m-x-1, it2, n, k-x-1);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
