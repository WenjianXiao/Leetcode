#include <iostream>
#include <queue>
using namespace std;
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
struct Node {
    TreeLinkNode* node;
    int level;
    Node(TreeLinkNode* node, int level):node(node),level(level){}
};
class Solution {
public:
    void connect1(TreeLinkNode *root) {
        if (root == NULL) return;
        Node* node = new Node(root,0);
        queue<Node* > q;
        q.push(node);
        Node* last = NULL;
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node->node->left != NULL) {
                Node* left = new Node(node->node->left, node->level+1);
                q.push(left);
            }
            if (node->node->right != NULL) {
                Node* right = new Node(node->node->right, node->level+1);
                q.push(right);
            }
            if (last == NULL) {
                last = node;
                continue;
            }
            if (last->level < node->level) last->node->next = NULL;
            else last->node->next = node->node;
            last = node;
        }
        last->node->next=NULL;
    }
    void connect2(TreeLinkNode *root) {
        if (root == NULL || root->left == NULL) return ;
        root->left->next = root->right;
        if (root->next != NULL) root->right->next = root->next->left;
        connect2(root->left);
        connect2(root->right);
    }
    void connect3(TreeLinkNode *root) {
        if (root == NULL) return ;
        TreeLinkNode *cur;
        while (root->left != NULL) {
            cur = root;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next != NULL) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            root = root->left;
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
