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
    void connect(TreeLinkNode *root) {
        connect1(root);
    }
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
        if (root == NULL) return;
        TreeLinkNode *cur, *start, *nxt;
        while (root != NULL) {
            start = findFirstNode(root);
            nxt = findNextNode(root, start);
            cur = start;
            while (nxt != NULL) {
                cur->next = nxt;
                cur = nxt;
                nxt = findNextNode(root,cur);
            }
            root = start;
        }
    }
    TreeLinkNode* findFirstNode(TreeLinkNode *root) {
        if (root->left != NULL) return root->left;
        return findNextNode(root, root->left);
    }
    /* Notice: it has modified root, TreeLinkNode *&root */
    TreeLinkNode* findNextNode(TreeLinkNode *&root, TreeLinkNode *pre) {
        if (root->left == pre && root->right != NULL) return root->right;
        while (root->next) {
            root = root->next;
            if (root->left != NULL && root->left != pre) return root->left;
            if (root->right != NULL && root->right != pre) return root->right;
        }
        return NULL;
    }
    void connect3(TreeLinkNode *root) {
        TreeLinkNode dummy(-1);
        TreeLinkNode *pre = &dummy;
        TreeLinkNode *cur;
        while (root) {
            cur = root;
            while (cur) {
                if (cur->left) {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            root = dummy.next;
            pre = &dummy;
            pre->next = NULL;
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
