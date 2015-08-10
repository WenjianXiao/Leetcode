#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for binary tree
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
/*Solution 1*/
class Solution {
public:
    vector<int> preorderTraversal1(TreeNode *root) {
        vector<int> path;
        path.clear();
        stack<TreeNode *> st;
        if (root == NULL) return path;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            path.push_back(cur->val);
            if (cur->right != NULL) st.push(cur->right);
            if (cur->left != NULL) st.push(cur->left);
        }
        return path;
    }
    vector<int> preorderTraversal2(TreeNode *root) {
        vector<int> path;
        path.clear();
        stack<TreeNode *> st;
        TreeNode *cur = root;
        pushLeft(cur,path,st);
        while (!st.empty()) {
            cur = st.top();
            st.pop();
            pushLeft(cur->right,path,st);
        }
        return path;
    }
    void pushLeft(TreeNode *cur,vector<int> &path,stack<TreeNode *> &st) {
        while (cur) {
            st.push(cur);
            path.push_back(cur->val);
            cur = cur->left;
        }
    }
    vector<int> preorderTraversal3(TreeNode *root) {
        vector<int> path;
        path.clear();
        TreeNode *pre;
        TreeNode *cur = root;
        while (cur) {
            if (cur->left == NULL) {
                path.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right != NULL && pre->right != cur)
                    pre = pre->right;
                if (pre->right == NULL) {
                    pre->right = cur;
                    path.push_back(cur->val);
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return path;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
