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
public:
    int closestValue(TreeNode* root, double target) {
        if(root == nullptr) {
            return -1;
        }

        if(root->val == target) {
            return target;
        }

        if(root->val < target) {
            int res = root->val;
            int right = closestValue(root->right, target);
            if(right == -1){
                return res;
            }

            double lDist = target - res;
            double rDist = right - target;
            if(rDist < lDist){
                return right;
            } else {
                return res;
            }
        } else {
            int res = root->val;
            int left = closestValue(root->left, target);
            if(left == -1) {
                return res;
            }
            double lDist = target - left;
            double rDist = res - target;
            if(rDist < lDist) {
                return res;
            } else {
                return left;
            }
        }

        return -1;
    }
};