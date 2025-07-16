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
    static TreeNode* predecessor(TreeNode* root) {
        TreeNode* cur = root->left;
        while(cur->right != nullptr && cur->right != root) {
            cur = cur->right;
        }
        return cur;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> res;
        while(cur != nullptr) {
            if(cur->left == nullptr) {
                res.push_back(cur->val);
                cur = cur->right;
                continue;
            }
            TreeNode* pred = predecessor(cur);
            if(pred->right == cur) {
                pred->right = nullptr;
                cur = cur->right;
            } else {
                pred->right = cur;
                res.push_back(cur->val);
                cur = cur->left;
            }
        }
        return res;
    }
};