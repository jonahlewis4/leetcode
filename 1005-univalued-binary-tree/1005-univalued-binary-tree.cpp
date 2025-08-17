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
    TreeNode* pred(TreeNode* root) {
        TreeNode* cur = root->left;
        while(cur->right != nullptr && cur->right != root) {
            cur = cur->right;
        }
        return cur;
    }
public:
    bool isUnivalTree(TreeNode* root) {
        int key = root->val;
        TreeNode* cur = root;
        bool res = true;
        while(cur != nullptr) {
            if(cur->left == nullptr) {
                if(cur->val != key) {
                    res = false;
                }
                cur = cur->right;
            } else {
                TreeNode* prev = pred(cur);
                if(prev->right == cur) {
                    prev->right = nullptr;
                    if(cur->val != key) {
                        res = false;
                    }
                    cur = cur->right;
                } else {
                    prev->right = cur;
                    cur = cur->left;
                }
            }
        }
        return res;
    }
};