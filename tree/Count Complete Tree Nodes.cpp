#include <iostream>

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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = getDepth(root);
        if (depth == 1) return 1;
        int last = (1 << (depth-1)) - 1;
        int idx = my_binary_search(root, last,depth-1);
        int res = last + idx + 1;
        return res;
    }
    int getDepth(TreeNode* root) {
        if (root == NULL) return 0;
        else return getDepth(root->left) + 1;
    }
    int my_binary_search(TreeNode* root, int last, int step) {
        int left = 0;
        int right = last;
        while(left < right) {
            int mid = (left+right+1)/2;
            bool isNULL = isNULLNode(root,mid,step);
            if (isNULLNode(root,mid,step)) right = mid - 1;
            else left = mid;
        }
        return left;
    }
    bool isNULLNode(TreeNode *root, int last, int step) {
        int i;
        for (i = 0; i < step; i++) {
            int dir = ((last >> (step-i-1)) & 1);
            if (dir == 0) root = root->left;
            else root = root->right;
        }
        if (root == NULL) return true;
        else return false;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
