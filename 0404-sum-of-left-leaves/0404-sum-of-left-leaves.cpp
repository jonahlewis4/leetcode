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
    
    bool isLeaf(TreeNode* root) const {
        return root->left==nullptr && root->right==nullptr;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
    int dfs(TreeNode* root, bool isLeft) const {
        if(root == nullptr){
            return 0;
        }
        int sum = 0;
        if(isLeft && isLeaf(root)){
            sum += root->val;
        }
        sum += dfs(root->left, true);
        sum += dfs(root->right, false);
        return sum;
    }
};