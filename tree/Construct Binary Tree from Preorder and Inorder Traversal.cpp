#include <iostream>
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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        vector<int>::iterator pre_it = preorder.begin();
        vector<int>::iterator in_it = inorder.begin();
        return buildTreeHelper(pre_it,in_it,size);
    }
    TreeNode* buildTreeHelper(vector<int>::iterator pre_it, vector<int>::iterator in_it, int size) {
        if (size == 0) return NULL;
        TreeNode *root = new TreeNode(*pre_it);
        int idx = traversal(in_it,size,*pre_it);
        root->left = buildTreeHelper(pre_it+1,in_it,idx);
        root->right = buildTreeHelper(pre_it+idx+1,in_it+idx+1,size-idx-1);
        return root;
    }
    int traversal(vector<int>::iterator it, int size, int target) {
       vector<int>::iterator idx = it;
       for (; idx < it + size; idx++) {
            if (*idx == target) return idx-it;
       }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
