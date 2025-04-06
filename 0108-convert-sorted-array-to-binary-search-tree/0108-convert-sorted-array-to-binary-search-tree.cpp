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
    vector<int> nums;
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums = nums;
        auto root = create(0, nums.size() - 1);
        return root;
    }

    TreeNode* create(int l, int r){
        if(l > r){
            return nullptr;
        }
        if( l == r){
            return new TreeNode(nums[l]);
        }
        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        TreeNode* left = create(l, m - 1);
        TreeNode* right = create(m + 1, r);

        root->left = left;
        root->right = right;
        return root;
    }
};