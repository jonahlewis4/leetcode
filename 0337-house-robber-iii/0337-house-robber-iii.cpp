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
    pair<int, int> r(TreeNode* root) {
        if(!root) {
            return {0,0};
        }
        
        pair<int, int> left = r(root->left);
        pair<int, int> right = r(root->right);
            
        int dontUse = max(right.first, right.second) + max(left.first, left.second);

        int use = root->val + right.first + left.first;
        
        return {dontUse, use};


    }
public:
    int rob(TreeNode* root) {
        pair<int, int> res = r(root);
        return max(res.first, res.second);
    }
};