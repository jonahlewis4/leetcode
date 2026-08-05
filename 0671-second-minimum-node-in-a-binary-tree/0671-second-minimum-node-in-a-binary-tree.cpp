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
    static int smol(TreeNode* root, int smallest) {
        if(!root) {
            return -1;
        }
        int left = smol(root->left, smallest);
        int right = smol(root->right, smallest);
        
        int min = root->val > smallest ? root->val : -1;
        
        if(left > 0) {
            if(min < 0) {
                min = left;
            } else {
                min = std::min(min, left);
            }
        }

        if(right > 0) {
            if(min < 0) {
                min = right;
            } else {
                min = std::min(min, right);
            }
        }

        return min;
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        int smallestValue = root->val;
        int left = smol(root->left, smallestValue);
        int right = smol(root->right, smallestValue);

        return (left == -1 && right == -1) ? -1 : 
                left > 0 && right < 0 ? left : 
                right > 0 && left < 0 ? right : 
                min(left, right);                       

    }
};