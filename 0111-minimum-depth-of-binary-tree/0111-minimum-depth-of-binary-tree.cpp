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
    int minimum = INT_MAX;
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        dfs(root, 1);
        return minimum;
    }
    void dfs(TreeNode* cur, int depth){
        if(cur == nullptr){
            return;
        }
        if(cur -> left == nullptr && cur->right == nullptr){
            minimum = min(depth, minimum);
            return;
        }

        dfs(cur->left, depth + 1);
        dfs(cur->right, depth + 1);
    }
};