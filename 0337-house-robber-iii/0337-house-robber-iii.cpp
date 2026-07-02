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
    unordered_map<TreeNode*, int> cache;
    int rob(TreeNode* root, bool cooldown) {
        if(!root) {
            return 0;
        }
        
        int left;
        int right;
        if(cache.contains(root->left)){
            left = cache[root->left];
        } else {
            left = rob(root->left, false);
            cache[root->left] = left;
        }

        if(cache.contains(root->right)) {
            right = cache[root->right];
        } else {
            right = rob(root->right, false);
            cache[root->right] = right;
        }
        int dontUse = right + left;
    
        if(!cooldown) {
            //if you rob, descend with cooldown
            //if you don't rob, descend without cooldown
            int use = root->val + rob(root->left, true) + rob(root->right, true);
            return max(use, dontUse);
        }
        
        //if cooldown -> don't rob
        return dontUse;


    }
public:
    int rob(TreeNode* root) {
        return rob(root, false);
    }
};