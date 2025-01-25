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
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        if(root->val <= max(root->left)){
            return false;
        }
        if(root->val >= min(root->right)){
            return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
    long long max(TreeNode* root){
        if(root == nullptr){
            return (long long)INT_MIN - 1;
        }
        return std::max({(long long)root->val, max(root->left), max(root->right)});
    }
    long long min(TreeNode* root){
        if(root == nullptr){
            return (long long)INT_MAX + 1;
        }
        return std::min({(long long)root->val, min(root->left), min(root->right)});
    }
};