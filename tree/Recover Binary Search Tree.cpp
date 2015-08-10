#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *p=NULL, *q=NULL;
    TreeNode *prev=NULL;
    void recoverTree(TreeNode* root) {
        Inorder(root);
        swap(q->val,p->val);
    }
    void Inorder(TreeNode *root) {
        if (root == NULL) return;
        Inorder(root->left);
        if (prev != NULL && root->val < prev->val) {
            if (p == NULL) p = prev;
            q = root;
        }
        prev = root;
        Inorder(root->right);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
