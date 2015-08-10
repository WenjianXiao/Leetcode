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
struct Node {
    TreeNode *t_node;
    int max_val;
    int s_max_val;
};
class Solution {
public:
    int max_val;
    int maxPathSum1(TreeNode* root) {
        if (root == NULL) return 0;
        max_val = root->val;
        maxPathSum1Helper(root);
        return max_val;
    }
    int maxPathSum1Helper(TreeNode* root) {
        int tmp_val = root->val;
        int tmp_max_val = root->val;
        if (root->left != NULL) {
            int left_val = maxPathSum1Helper(root->left);
            if (left_val > 0) {
                tmp_max_val += left_val;
                tmp_val += left_val;
            }
        }
        if (root->right != NULL) {
            int right_val = maxPathSum1Helper(root->right);
            if (right_val + root->val > tmp_val) tmp_val = right_val + root->val;
            if (right_val > 0) tmp_max_val += right_val;
        }
        if (tmp_max_val > max_val) max_val = tmp_max_val;
        return tmp_val;
    }
    /* Simplify the code */
    int maxPathSum2(TreeNode* root) {
        if (root == NULL) return 0;
        int max_val = root->val;
        maxPathSum2Helper(root, max_val);
        return max_val;
    }
    int maxPathSum2Helper(TreeNode* root, int &max_val) {
        int res;
        if (!root) return 0;
        int l = maxPathSum2Helper(root->left, max_val);
        int r = maxPathSum2Helper(root->right, max_val);
        max_val = max(max_val, max(0,l)+max(0,r)+root->val);
        res = max(max(r,l),0) + root->val;
        return res;
    }

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
