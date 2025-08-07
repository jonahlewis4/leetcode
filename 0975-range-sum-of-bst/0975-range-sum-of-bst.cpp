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
    int sum = 0;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr) {
            return sum;
        }
        if(root->val < low) {
            rangeSumBST(root->right, low, high);
            return sum;
        } else if(root->val > high) {
            rangeSumBST(root->left, low, high);
            return sum;
        } else {
            rangeSumBST(root->right, low, high);
            rangeSumBST(root->left, low, high);
        }
        sum += root->val;
        return sum;
    }
};