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
    TreeNode* getPredecessor(const TreeNode *const node) {
        TreeNode* cur = node->left;
        while(cur->right != nullptr && cur->right != node) {
            cur = cur->right;
        }
        return cur;
    }
public:
    int minDiffInBST(TreeNode* root) {
        TreeNode* cur = root;
        int diff = INT_MAX;
        int previous = -1;
        void (*handleNode)(TreeNode*, int&, int&) = [](TreeNode* node, int& previous, int& diff){
            if(previous != -1) {
                int localDiff = node->val - previous;
                diff = min(localDiff, diff);
            }
            previous = node->val;
        };
        while(cur != nullptr) {
            if(cur->left == nullptr) {
                handleNode(cur, previous, diff);
                cur = cur->right;
            } else {
                TreeNode* predecessor = getPredecessor(cur);
                if(predecessor->right != nullptr){
                    handleNode(cur, previous, diff);
                    cur = cur->right;
                    predecessor->right = nullptr;
                } else {
                    predecessor->right = cur;
                    cur = cur->left;
                }
            }
        }   


        return diff;
    }
};