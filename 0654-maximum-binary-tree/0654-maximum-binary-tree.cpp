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
    static TreeNode* build(const vector<int>& nums, int l, int r) {
        if(l > r){
            return nullptr;
        }

        vector<int>::const_iterator itr = max_element(nums.begin() + l, nums.begin() + r + 1);
        int maxI = itr - nums.begin();

        TreeNode* newNode = new TreeNode(*itr);
        newNode->left = build(nums, l, maxI-1);
        newNode->right = build(nums, maxI+1, r);
        return newNode;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};