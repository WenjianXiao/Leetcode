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
    TreeNode* p_far;
    void flatten1(TreeNode* root) {
        flattenHelper(root);
    }
    /* Solution 1: preoder traversal */
    TreeNode* flattenHelper(TreeNode* root) {
        if (root == NULL) return NULL;
        p_far = root;
        TreeNode *tmp = root->right;
        root->right=flattenHelper(root->left);
        root->left = NULL;
        p_far->right = flattenHelper(tmp);
        return root;
    }
    /* Solution 2 : iteration */
    void flatten2(TreeNode *root) {
        if (root == NULL) return;
        while (root) {
            if (root->left != NULL) {
                TreeNode *pre = root->left;
                while (pre->right != NULL) pre = pre->right;
                pre->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
