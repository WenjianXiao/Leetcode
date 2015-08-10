#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root) {
        while(!s.empty()) s.pop();
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *next = s.top();
        s.pop();
        pushLeft(next->right);
        return next->val;
    }
    void pushLeft(TreeNode *root) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }
};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
