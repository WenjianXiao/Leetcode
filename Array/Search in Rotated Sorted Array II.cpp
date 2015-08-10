#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        search1(nums, target);
    }
    /** Solution 2: binary_find. there are 3 cases:
    ** nums[mid] > nums[l] : so [l,mid] �����ڵ��������ģ����target�������Χ�ڣ���ôr = mid - 1;��֮, l = mid + 1;
    ** nums[mid] < nums[l] : ����[l,mid]���ȵ������½���ĳ����ٵ��������target�����������ڣ���ôl = mid + 1;��֮r = mid - 1;
    ** nums[mid] = nums[l] : �޷��ж�[mid,l]��������������nums[mid] != nums[r],˵��[mid,l]֮���ǲ���ġ���ôl = mid + 1;
    ** ��֮��ֻ��˵��l,r�����㲻����������
    **/
    bool search2(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (target == nums[mid]) return true;
            else if (nums[mid] > nums[l]) {
                if (target >= nums[l] && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else if (nums[mid] < nums[l]) {
                if (target > nums[mid] && target < nums[l]) l = mid + 1;
                else r = mid - 1;
            } else {
                if (nums[mid] == nums[r]) {
                    l++; r--;
                } else {
                    l = mid + 1;
                }
            }
        }
        return false;
    }
    /** Solution 1: ��������Ļ���˼�������ҵ�ת�۵㣬����С���Ǹ��㡣Ȼ���ٸ���target��ֵ���жϲ�����һ�Ρ�
    ** ��Ϊ����֪��[0,mid)����������[mid, n-1]���������ġ����target > nums[n-1]����ô����ǰһ���в��ҡ�������
    ** ��һ���в��ҡ�
    **/
    bool search1(vector<int>& nums, int target) {
        int nums_size = nums.size();
        if (nums_size == 0) return false;
        int mid_point = find_mid_point(nums);
        bool res=false;
        if (target > nums[nums_size-1]) {
            res = b_find(nums,0,mid_point-1,target);
        } else {
            res = b_find(nums,mid_point,nums_size-1,target);
        }
        return res;
    }
    /** ��nums[mid]��nums[end]����ʱ�������Ǻܺ�ȥ���жϵ�ת�۵�ķ�Χ�ġ�
    ** ��nums[mid] > nums[end]��˵���϶���[mid+1, end]�Ρ�
    ** ��nums[mid] < nums[end],˵����[l, mid]�Ρ�
    ** �����ʱ���޷��ж�������һ���ϣ���ôֻ�б���[l,r]��η�Χ���ҵ�һ������������
    ** �������ɡ�
    **/
    int find_mid_point(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int end = right;
        while (left<right) {
            int mid = (left+right)/2;
            if (nums[mid] > nums[end]) left = mid+1;
            else if (nums[mid] < nums[end]) right = mid;
            else {
                int i;
                for (i = mid; i <= right; i++) {
                    if (nums[i] > nums[end]) {
                        left = i+1;
                        break;
                    }
                    else if (nums[i] < nums[end]) {
                        return i;
                    }
                }
                if (i == right+1) right = mid;
            }
        }
        return left;
    }
    bool b_find(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = (left+right)/2;
            if (target == nums[mid]) return true;
            else if (target < nums[mid]) right = mid - 1;
            else left = mid+1;
        }
        return false;
    }
};
int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    Solution solu;
    bool res = solu.search(nums,1);
    cout << res << endl;
    cout << "Hello world!" << endl;
    return 0;
}
