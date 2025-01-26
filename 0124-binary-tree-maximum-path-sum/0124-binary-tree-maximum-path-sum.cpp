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
private:
    int maxSum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        calc(root);
        return maxSum;
    }
    int calc(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left = calc(root->left);
        int right = calc(root->right);
        maxSum = max({left + root->val, right + root->val, root->val, maxSum, left + right + root->val});
        return max({root->val + left, root->val + right, root->val});
    }
};