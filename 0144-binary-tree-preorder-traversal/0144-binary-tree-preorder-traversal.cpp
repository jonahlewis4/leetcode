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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;
        while(cur != nullptr) { 
            if(cur->left == nullptr){
                ans.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prede = pred(cur);
                if(prede->right == nullptr) {
                    ans.push_back(cur->val);
                    prede->right = cur;
                    cur = cur->left;
                } else {
                    prede->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};