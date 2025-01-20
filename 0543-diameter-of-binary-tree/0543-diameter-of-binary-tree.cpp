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
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        dfs(root, max);
        return max;
        
    }
    int dfs(TreeNode* root, int &maxx){
        if(root == nullptr){
            return 0;
        }
        int left = dfs(root->left, maxx);
        int right = dfs(root->right, maxx);
        
        maxx = std::max(maxx, left + right);

        return std::max(left, right) + 1;
    }
};