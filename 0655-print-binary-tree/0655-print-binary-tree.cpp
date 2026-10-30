/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int height(TreeNode const *const root) const {
        if(!root) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    void print(TreeNode const *const root, int row, vector<vector<string>>& res, int l, int r) {
        if(!root){
            return;
        }
        int col = (l + r)/2;
        res[row][col] = to_string(root->val);
        

       

        print(root->left, row+1, res, l, col - 1);
        print(root->right, row+1, res, col + 1, r);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int m = height(root);
        int n = (1 << m) - 1;
        vector<vector<string>> res(m, vector<string>(n));
        print(root, 0, res, 0, n - 1);
        return res;
    }
};