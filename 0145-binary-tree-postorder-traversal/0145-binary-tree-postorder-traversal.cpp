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
vector<int> res;
public:

    vector<int> postorderTraversal(TreeNode* root) {
        //left, right , middle
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        traverse(root->left);
        traverse(root->right);
        res.push_back(root->val);
    }
};