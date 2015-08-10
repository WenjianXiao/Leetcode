#include <iostream>
#include <math.h>
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
    /* Solution 1 */
    bool isBalanced1(TreeNode* root) {
        if (root == NULL) return true;
        int lheight = depth(root->left);
        int rheight = depth(root->right);
        if (fabs(lheight-rheight) > 1) return false;
        else if (isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
    }
    int depth(TreeNode *root) {
        if (root == NULL) return 0;
        else return max(depth(root->left),depth(root->right)) + 1;
    }
    /* Solution 2 */
    bool isBalanced2(TreeNode* root) {
        int height = 0;
        return isBalancedHelper(root,height);
    }
    bool isBalancedHelper(TreeNode *root, int &height) {
        if (root == NULL) return true;
        int l_h = 0, r_h = 0;
        bool l_isBalanced = isBalancedHelper(root->left, l_h);
        bool r_isBalanced = isBalancedHelper(root->right, r_h);
        height = max(l_h, r_h) + 1;
        if (l_isBalanced && r_isBalanced && (fabs(l_h - r_h) <= 1)) {
            return true;
        }
        return false;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
