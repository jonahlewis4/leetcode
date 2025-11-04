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
    int numSub = 0;
public:
    int countUnivalSubtrees(TreeNode* root) {
        check(root);
        return numSub;
    }

    bool check(TreeNode* root) {
        if(root == nullptr) {
            return false;
        }

        if(root->left == nullptr && root->right == nullptr){
            numSub++;
            return true;
        }

        bool leftCheck = check(root->left);
        bool rightCheck = check(root->right);

        if(root->left == nullptr && rightCheck && root->val == root->right->val){
            numSub++;
            return true;
        }

        if(root->right == nullptr && leftCheck && root->val == root->left->val){
            numSub++;
            return true;
        }

        if(leftCheck && rightCheck && root->val == root->left->val && root->val == root->right->val){
            numSub++;
            return true;
        }

        return false;
    }
};