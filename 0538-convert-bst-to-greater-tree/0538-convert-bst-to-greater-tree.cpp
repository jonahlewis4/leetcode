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
    int r(TreeNode* root, int bonus) {
        if(!root) {
            return 0;
        }

        int right = r(root->right, bonus);
        int oldVal = root->val;
        root->val += right + bonus;
        int left = r(root->left, root->val);
        // cout<<"_____________"<<endl;
        // cout<<"val : "<<oldVal<<endl;
        // cout<<"left: "<<left<<endl;
        // cout<<"right: "<<right<<endl;
        // cout<<"bonus: "<<bonus<<endl;
        // cout<<"new val : "<<root->val<<endl;
        return left + right + oldVal;

    }
public:
    TreeNode* convertBST(TreeNode* root) {
        r(root, 0);
        return root;
    }
};