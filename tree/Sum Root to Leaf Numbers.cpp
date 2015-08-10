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
    int sum;
    int p_sum;
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        sum = 0;
        p_sum = 0;
        cal_sum(root);
        return sum;
    }
    void cal_sum(TreeNode *root) {
        p_sum = p_sum*10 + root->val;
        if (root->left == NULL && root->right == NULL) sum += p_sum;
        if (root->left != NULL) cal_sum(root->left);
        if (root->right != NULL) cal_sum(root->right);
        p_sum = (p_sum - root->val)/10;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
