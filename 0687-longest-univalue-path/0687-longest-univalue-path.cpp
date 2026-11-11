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
    int longestPath = 0;
    int call(TreeNode* root, int prev) {
        if(!root){
            return 0;
        }
        
        bool inStreak = root->val == prev;
        int left = call(root->left, root->val);
        int right = call(root->right, root->val);
        int path = left + right;
        longestPath = max(path, longestPath);
        if(inStreak) {
            return 1 + max(left, right);
        } else {
            return 0;
        }

    }
public:
    int longestUnivaluePath(TreeNode* root) {
        call(root, INT_MIN);
        return longestPath;
    }
};