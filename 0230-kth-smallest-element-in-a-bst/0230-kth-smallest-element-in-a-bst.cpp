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
int ans;
int count;
public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        ans = -1;
        dfs(root, k);
        return this->ans; 
    }
    void dfs(TreeNode* root, int k){
        if(root == nullptr){
            return;
        }
        dfs(root->left, k);
        this->count++;
        if(this->count == k){
            ans = root->val;
        }
        dfs(root->right, k);
    }
};