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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> stk;
        for(const int i : nums) {
            TreeNode* node = new TreeNode(i);
            TreeNode* chain = nullptr;
            while(!stk.empty() && stk.top()->val < node->val){
                stk.top()->right = chain;
                chain = stk.top();
                stk.pop();
            }
            node->left = chain;
            stk.push(node);
            
            
        }
        TreeNode* chain = nullptr;
        while(stk.size() > 1) {
            stk.top()->right = chain;
            chain = stk.top();
            stk.pop();
        }
        stk.top()->right = chain;
        return stk.top();
    }
};