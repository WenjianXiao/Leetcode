#include <iostream>
#include <vector>
#include <queue>
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
struct Node {
    TreeNode *node;
    int level;
    Node(TreeNode *node, int level) : node(node),level(level) {}
};
class Solution {
public:
    vector<int> rightSideView1(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        queue<Node*> q;
        Node *node = new Node(root,0);
        q.push(node);
        int cur_level = 0;
        int last_val = root->val;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node->level != cur_level) res.push_back(last_val);
            last_val = node->node->val;
            if (node->node->left != NULL) {
                Node *left = new Node(node->node->left, node->level+1);
                q.push(left);
            }
            if (node->node->right != NULL) {
                Node *right = new Node(node->node->right, node->level+1);
                q.push(right);
            }
            cur_level = node->level;
        }
        res.push_back(last_val);
        return res;
    }
    /* Solution 2 : use cnt for controlling the level
    we can use other ways like the Binary Tree Level Order Traversal */
    vector<int> rightSideView2(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            int i;
            TreeNode *cur;
            for(i = 0; i < cnt; i++) {
                cur = q.front();
                q.pop();
                if (cur->left != NULL) q.push(cur->left);
                if (cur->right != NULL) q.push(cur->right);
            }
            res.push_back(cur->val);
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
