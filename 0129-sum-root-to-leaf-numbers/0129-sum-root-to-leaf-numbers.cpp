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
    static bool isLeaf(TreeNode* n) {
        return n->left == nullptr && n->right == nullptr;
    }
    int res = 0;
public:
    int sumNumbers(TreeNode* root) {
        r(0, root);
        return res;
    }
    void r(int runSum, TreeNode* cur){
        if(cur == nullptr){
            return;
        }
        runSum *= 10;
        runSum += cur->val;

        if(isLeaf(cur)) {
            res += runSum;
            return;
        }
        r(runSum, cur->left);
        r(runSum, cur->right);

    }
    
};