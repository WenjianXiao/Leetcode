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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        vector<int>::iterator post_it = postorder.begin();
        vector<int>::iterator in_it = inorder.begin();
        return buildTreeHelper(post_it,in_it,size);
    }
    TreeNode* buildTreeHelper(vector<int>::iterator post_it, vector<int>::iterator in_it, int size) {
        if (size == 0) return NULL;
        TreeNode *root = new TreeNode(*(post_it+size-1));
        int idx = traversal(in_it,size,*(post_it+size-1));
        root->left = buildTreeHelper(post_it,in_it,idx);
        root->right = buildTreeHelper(post_it+idx,in_it+idx+1,size-idx-1);
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
