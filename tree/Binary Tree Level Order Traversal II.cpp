#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        reverse(res.begin(),res.end());
        return res;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
