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
bool res = false;
int target;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        target = targetSum;
        dfs(root, 0);

        return res;
    }
    void dfs(TreeNode* root, int cur){
        if(root == nullptr){
            return;
        }
        cur += root->val;
        if(cur == target && root->left == nullptr && root->right == nullptr){
            res = true;
        }
        

        dfs(root->left, cur);
        dfs(root->right, cur);

    }
};