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
    int numGood = 0;
public:
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return this->numGood;
    }

    void dfs(TreeNode* root, int maximum) {
        if(root == nullptr){
            return;
        }
        if(root->val >= maximum){
            this->numGood++;
        }
        dfs(root->left, max(maximum, root->val));
        dfs(root->right, max(maximum, root->val));
    }
};