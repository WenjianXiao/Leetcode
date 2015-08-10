#include <iostream>
#include <vector>
#include <cstring>
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
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees2(n);
    }
    /* Solution 1 */
    vector<TreeNode*> generateTrees1(int n) {
        TreeNode *root = NULL;
        int i;
        vector<TreeNode*> res;
        res.clear();
        if (n == 0) {
            res.push_back(root);
            return res;
        }
        for(i = 1; i <= n ; i++) {
            vector<TreeNode *> tmp;
            tmp = generateRootTree(i,1,n);
            int j;
            int size = tmp.size();
            for (j = 0; j < size; j++) res.push_back(tmp[j]);
        }
        return res;
    }
    vector<TreeNode *> generateRootTree(int r, int min_val, int max_val) {
        int i,j;
        vector<TreeNode *> res;
        res.clear();
        if (min_val == max_val) {
            TreeNode *root = new TreeNode(r);
            root->left = root->right = NULL;
            res.push_back(root);
            return res;
        }
        if (min_val == r) {
            for (j = r+1; j <= max_val; j++) {
                vector<TreeNode *> tmp;
                tmp = generateRootTree(j,r+1,max_val);
                int size = tmp.size();
                for (i = 0; i < size; i++) {
                    TreeNode *root = new TreeNode(r);
                    root->left = NULL;
                    root->right = tmp[i];
                    res.push_back(root);
                }
            }
            return res;
        }
        if (max_val == r) {
            for (i = min_val; i < r; i++) {
                vector<TreeNode *> tmp = generateRootTree(i,min_val,r-1);
                int size = tmp.size();
                for (j = 0; j < size; j++) {
                    TreeNode *root = new TreeNode(r);
                    root->right = NULL;
                    root->left = tmp[j];
                    res.push_back(root);
                }
            }
            return res;
        }
        for(i = min_val; i < r; i++) {
            for (j = r+1; j <= max_val; j++) {
                vector<TreeNode*> ltrees = generateRootTree(i,min_val,r-1);
                vector<TreeNode*> rtrees = generateRootTree(j,r+1,max_val);
                int l_size = ltrees.size();
                int r_size = rtrees.size();
                int k,m;
                for (k = 0; k < l_size; k++) {
                    for (m = 0; m < r_size; m++) {
                        TreeNode *root = new TreeNode(r);
                        root->left = ltrees[k];
                        root->right = rtrees[m];
                        res.push_back(root);
                    }
               }
            }
        }
        return res;
    }
    void Traversal(TreeNode *root, int &cnt) {
        if (root == NULL) return;
        cnt++;
        cout << root->val << endl;
        Traversal(root->left,cnt);
        Traversal(root->right,cnt);
    }

    /*Solution 2 : simplify the code of Solution 1 */
    vector<TreeNode*> generateTrees2(int n) {
        return generateTreesHelper(1,n);

    }
    vector<TreeNode *> generateTreesHelper(int s, int e) {
        vector<TreeNode *> res;
        if (s > e) {
            res.push_back(NULL);
            return res;
        }
        int k;
        for (k = s; k <= e; k++) {
            vector<TreeNode *> lf = generateTreesHelper(s,k-1);
            vector<TreeNode *> rf = generateTreesHelper(k+1, e);
            int l_size = lf.size();
            int r_size = rf.size();
            int i,j;
            for (i = 0; i < l_size; i++) {
                for (j = 0; j < r_size; j++) {
                    TreeNode *root = new TreeNode(k);
                    root->left = lf[i];
                    root->right = rf[j];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution solu;
    int n = 1;
    vector<TreeNode*> res = solu.generateTrees(n);
    cout << res.size()<<endl;
    int i;
    /*for (i = 0; i < res.size();i++) {
        int cnt = 0;
        solu.Traversal(res[i],cnt);
        if (cnt != n) {
            cout << i << " cnt: "<<cnt;
            cout << " error"<<endl;
        }
    }*/
        //cout << res[i] << endl;
    cout << "Hell world!" << endl;
    return 0;
}
