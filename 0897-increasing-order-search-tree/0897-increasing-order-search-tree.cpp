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
    TreeNode* prev = nullptr;
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode sen;
        sen.right = root;
        prev = &sen;
        r(root);
        return sen.right;
    }
    void r(TreeNode* cur){
        if(!cur) {
            return;
        }
        r(cur->left);
        cout<<cur->val<<endl;
        if(prev) {
            prev->right = cur;
        }
        prev = cur;
        r(cur->right);
        cur->left = nullptr;
    }
};