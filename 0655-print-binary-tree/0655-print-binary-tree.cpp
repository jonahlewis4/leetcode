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
    void print(TreeNode const *const root, int r, int c, vector<vector<string>>& res) {
        if(!root){
            return;
        }
        cout<<root->val<<endl;
        res[r][c] = to_string(root->val);
        
        int shift = res.size() - r - 2;
        if(shift < 0){
            return;
        }
        int offset = 1<<(res.size() - r - 2);
        print(root->left, r+1, c - offset, res);
        print(root->right, r+1, c + offset, res);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int m = height(root);
        int n = (1 << m) - 1;
        vector<vector<string>> res(m, vector<string>(n));
        print(root, 0, n/2, res);
        return res;
    }
};