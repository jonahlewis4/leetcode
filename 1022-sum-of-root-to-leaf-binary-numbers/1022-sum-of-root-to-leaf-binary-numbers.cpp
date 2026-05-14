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
    int sum = 0;
    static bool isLeaf(const TreeNode *const node){
        return !node->left && !node->right;
    }
    void r(const TreeNode* const node, int run){
        if(!node){
            return;
        }
        run <<=1;
        run += node->val;
        if(isLeaf(node)){
            sum += run;
        } else {
            r(node->left, run);
            r(node->right, run);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        r(root, 0);
        return sum;
    }
};