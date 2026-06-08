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
    TreeNode* predecessor(TreeNode* const root) {
        TreeNode* cur = root->left;
        while(cur->right != nullptr && cur->right != root) {
            cur = cur->right;
        }
        return cur;
    }

    TreeNode* l = nullptr;
    TreeNode* r = nullptr;
    TreeNode* prev = nullptr;
    void visit(TreeNode* node) {
        if(!node) {
            return;
        }
        if(prev && prev->val > node->val) {
            if(!l){
                l = prev;
            }
            r = node;
        }
        prev = node;
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* cur = root;
        while(cur != nullptr) {
            if(!cur->left){
                visit(cur);
                cur = cur->right;
            } else {
                TreeNode* pred = predecessor(cur);
                if(pred->right != cur) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    TreeNode* right = cur->right;
                    pred->right = nullptr;
                    visit(cur);
                    cur = right;
                }
            }
        }
        swap(l->val, r->val);
    }
};