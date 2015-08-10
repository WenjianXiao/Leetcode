#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <algorithm>
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
/*Solution 1 左右中的逆是中右左，就转换成了前序遍历*/
class Solution {
public:
    vector<int> postorderTraversal1(TreeNode *root) {
        vector<int> path;
        path.clear();
        stack<TreeNode *> st;
        if (root == NULL) return path;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            path.push_back(cur->val);
            if (cur->left != NULL) st.push(cur->left);
            if (cur->right != NULL) st.push(cur->right);
        }
        reverse(path.begin(),path.end());
        return path;
    }
    vector<int> postorderTraversal2(TreeNode *root) {
        vector<int> path;
        path.clear();
        TreeNode *pre = NULL;
        TreeNode *cur = root;
        while (cur) {
            if (cur->right == NULL) {
                path.push_back(cur->val);
                cur = cur->left;
            } else {
                pre = cur->right;
                while (pre->left != NULL && pre->left != cur)
                    pre = pre->left;
                if (pre->left == NULL) {
                    pre->left = cur;
                    path.push_back(cur->val);
                    cur = cur->right;
                } else {
                    pre->left = NULL;
                    cur = cur->left;
                }
            }
        }
        reverse(path.begin(),path.end());
        return path;
    }
    vector<int> postorderTraversal3(TreeNode *root) {
        vector<int> path;
        path.clear();
        stack<TreeNode *> st;
        TreeNode *pre = root;
        TreeNode *cur = root;
        if (root == NULL) return path;
        st.push(root);
        while (!st.empty()) {
            cur = st.top();
            if (cur->right == pre || cur->left == pre || (cur->right == NULL && cur->left == NULL)) {
                st.pop();
                path.push_back(cur->val);
                pre = cur;
            } else {
                if (cur->right != NULL) st.push(cur->right);
                if (cur->left != NULL) st.push(cur->left);
            }
        }
        return path;
    }
};
int main()
{
    TreeNode l(1);
    TreeNode r(3);
    TreeNode root(2);
    root.left = &l;
    root.right = &r;
    Solution s;
    printf("xxx\n");
    vector<int> v = s.postorderTraversal1(&root);
    printf("xxxs\n");
    vector<int>::iterator it = v.begin();
    for(;it != v.end();it++){
        printf("%d\n",*it);
    }
    cout << "Hello world!" << endl;
    return 0;
}
