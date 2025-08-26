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
        while(cur->right != root && cur->right != nullptr) {
            cur = cur->right;
        }
        return cur;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        while(cur != nullptr) {
            if(cur->left == nullptr) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prede = pred(cur);
                if(prede->right == nullptr){
                    prede->right = cur;
                    cur = cur->left;
                } else {
                    res.push_back(cur->val);
                    prede->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};