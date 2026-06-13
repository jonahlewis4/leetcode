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
    int tilt = 0;
    int _r(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int l = _r(root->left);
        int r = _r(root->right);
        int localTilt = abs(l - r);
        tilt += localTilt;
        return l + r + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        _r(root);
        return tilt;
    }
};