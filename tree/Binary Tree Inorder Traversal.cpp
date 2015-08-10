#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > st;
        go_far_left(root,st);
        while(!st.empty()) {
            TreeNode* pnode = st.top();
            st.pop();
            res.push_back(pnode->val);
            go_far_left(pnode->right,st);
        }
        return res;
    }
    void go_far_left(TreeNode* root, stack<TreeNode* > &st) {
        while (root!=NULL) {
            st.push(root);
            root = root->left;
        }
    }
    vector<int> inorderTraversal2(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> st;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
    vector<int> inorderTraversal3(TreeNode *root) {
        vector<int> res;
        TreeNode *pre = NULL;
        TreeNode *cur = root;
        while (cur) {
            if (cur->left == NULL) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right != NULL && pre->right != cur) {
                    pre = pre->right;
                }
                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    res.push_back(cur->val);
                    cur = cur->right;
                    pre->right = NULL;
                }
            }
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
