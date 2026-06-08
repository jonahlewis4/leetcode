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
    TreeNode* firstDecrease = nullptr;
    TreeNode* secondDecrease = nullptr;
    TreeNode* prev = nullptr;
    void r(TreeNode*const root) {
        if(!root) {
            return;
        }
        r(root->left);
        if(prev != nullptr && prev->val > root->val){
            if(!secondDecrease) {
                firstDecrease = prev;
            }
            secondDecrease = root;

        }
        prev = root;
        r(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        

        r(root);
        swap(firstDecrease->val, secondDecrease->val);

    }
};