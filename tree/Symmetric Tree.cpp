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
    /* Solution 1 */
    bool isSymmetric(TreeNode* root) {
        return isSymmetric1(root);
    }
    bool isSymmetric1(TreeNode* root) {
        if (root == NULL) return true;
        if (!isSameNode(root->left, root->right)) return false;
        stack<TreeNode* > pst;
        stack<TreeNode* > qst;
        if (root->left == NULL) return true;
        pst.push(root->left);
        qst.push(root->right);
        while (!pst.empty()) {
            TreeNode *pnode = pst.top();
            TreeNode *qnode = qst.top();
            pst.pop();
            qst.pop();
            if (!isSameNode(pnode->left, qnode->right) ||
                !isSameNode(pnode->right, qnode->left)) return false;
            if (pnode->left != NULL) {
                pst.push(pnode->left);
                qst.push(qnode->right);
            }
            if (pnode->right != NULL) {
                pst.push(pnode->right);
                qst.push(qnode->left);
            }
        }
        return true;
    }
    bool isSameNode(TreeNode *p, TreeNode *q) {
        if (p==NULL && q==NULL) return true;
        else if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;
        return true;
    }

    /* Solution 2 */
    bool isSymmetric2(TreeNode* root) {
        if (root == NULL) return true;
        return isSymmetricTwo(root->left, root->right);
    }
    bool isSymmetricTwo(TreeNode* p, TreeNode* q) {
        if (p==NULL && q==NULL) return true;
        else if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;
        return isSymmetricTwo(p->left, q->right) && isSymmetricTwo(p->right,q->left);
    }

    /* Solution 3 */
    bool isSymmetric3(TreeNode* root) {
        if (root == NULL) return true;
        reverseTree(root->left);
        return isSameTree(root->left, root->right);
    }
    void reverseTree(TreeNode *root) {
        if (root == NULL) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        reverseTree(root->left);
        reverseTree(root->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL && q==NULL) return true;
        else if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right,q->right);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
