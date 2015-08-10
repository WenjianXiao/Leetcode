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
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        pathSumHelper(root,sum);
        return res;
    }
    void pathSumHelper(TreeNode* root, int sum) {
        if (root == NULL) return ;
        if (root->right == NULL && root->left == NULL)
        {
            if (sum == root->val)
            {
                tmp.push_back(sum);
                res.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
        if (root->right == NULL) {
            tmp.push_back(root->val);
            pathSumHelper(root->left, sum-root->val);
            tmp.pop_back();
            return;
        }
        if (root->left == NULL) {
            tmp.push_back(root->val);
            pathSumHelper(root->right, sum-root->val);
            tmp.pop_back();
            return;
        }
        tmp.push_back(root->val);
        pathSumHelper(root->left, sum-root->val);
        pathSumHelper(root->right, sum-root->val);
        tmp.pop_back();
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
