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
    static int lHeight(TreeNode* root) {
        int h = 0;
        while(root != nullptr) {
            root = root->left;
            h++;
        }
        return h;
    }
    static int rHeight(TreeNode* root) {
        int h = 0;
        while(root != nullptr) {
            root = root->right;
            h++;
        }
        return h;
    }
    static int recurse(TreeNode* root) {
        int left = lHeight(root);
        int right = rHeight(root);

        if(left == right) {
            return (1 << left) - 1;
        } else {
            return 1 + recurse(root->left) + recurse(root->right);
        }
    }
public:
    int countNodes(TreeNode* root) {
        return recurse(root);
    }


};