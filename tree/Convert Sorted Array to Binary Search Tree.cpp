#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        int size = nums.size();
        return sortedArrayToBSTHelper(it, size);

    }
    TreeNode* sortedArrayToBSTHelper(vector<int>::iterator it, int size) {
        if (size == 0) return NULL;
        TreeNode *root = new TreeNode(*(it+size/2));
        root->left = sortedArrayToBSTHelper(it, size/2);
        root->right = sortedArrayToBSTHelper(it+size/2+1,size-size/2-1);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
