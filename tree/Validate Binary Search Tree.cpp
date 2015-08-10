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
    TreeNode *pre2;
    bool isValidBST(TreeNode* root) {
        return isValidBST2(root);
    }
    bool isValidBST1(TreeNode* root) {
        if (root == NULL) return true;
        int cnt = 0;
        int prev = 0;
        bool flag = true;
        traversalBST(root,cnt,prev,flag);
        return flag;
    }
    void traversalBST(TreeNode *root,int &cnt,int &prev,bool &flag) {
        if (root == NULL) return;
        traversalBST(root->left,cnt,prev,flag);
        if (cnt != 0 && root->val <= prev) {flag=false; return;}
        cnt++;
        prev = root->val;
        traversalBST(root->right,cnt,prev,flag);
    }
    bool isValidBST2(TreeNode* root) {
        if (root == NULL) return true;
        int flag = true;
        flag = isValidBST2(root->left);
        if (!flag) return false;
        else {
            if (pre2 != NULL && pre2->val >= root->val) return false;
            pre2 = root;
            flag = isValidBST2(root->right);
            return flag;
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
