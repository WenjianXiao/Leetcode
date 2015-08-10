#include <iostream>
#include <queue>
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
struct Node {
    TreeNode *node;
    int level;
    Node(TreeNode *node, int level) : node(node), level(level) {}
};
class Solution {
public:
    vector<vector<int>> res;
    /* Solution 1 : add level tag for every node */
    vector<vector<int>> levelOrder1(TreeNode* root) {
        res.clear();
        if (root == NULL) return res;
        queue<Node> q;
        q.push(Node(root,0));
        int cur_level = 0;
        vector<int> tmp;
        while (!q.empty()) {
            Node node = q.front();
            q.pop();
            if (node.node->left!=NULL) {
                q.push(Node(node.node->left, node.level+1));
            }
            if (node.node->right!=NULL) {
                q.push(Node(node.node->right,node.level+1));
            }
            if (node.level == cur_level) tmp.push_back(node.node->val);
            else {
                cur_level = node.level;
                res.push_back(tmp);
                tmp.clear();
                tmp.push_back(node.node->val);
            }
        }
        res.push_back(tmp);
        return res;
    }
    /* Solution 2: Depth-first traversal */
    vector<vector<int>> levelOrder2(TreeNode* root) {
        res.clear();
        levelOrder2Helper(root, 0);
        return res;
    }
    void levelOrder2Helper(TreeNode* root,int level) {
        if (root == NULL) return;
        if (res.size() > level) res[level].push_back(root->val);
        else {
            vector<int> tmp;
            tmp.push_back(root->val);
            res.push_back(tmp);
        }
        levelOrder2Helper(root->left, level+1);
        levelOrder2Helper(root->right, level+1);
    }
    /* Solution 3 : two queue for BFS */
    vector<vector<int>> levelOrder3(TreeNode* root) {
        res.clear();
        if (root == NULL) return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode *> q1;
            vector<int> tmp;
            while (!q.empty()) {
                TreeNode *cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if (cur->left != NULL) q1.push(cur->left);
                if (cur->right != NULL) q1.push(cur->right);
            }
            res.push_back(tmp);
            q = q1;
        }
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
