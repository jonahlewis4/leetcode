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
    int diff = INT_MAX;
    int prev = -1;
    void r(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        r(root->left);
        if(prev != -1) {
            int localDiff = root->val - prev;
            diff = min(localDiff, diff);
        }
        prev = root->val;
        r(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        r(root);
        return diff;        
    }
};