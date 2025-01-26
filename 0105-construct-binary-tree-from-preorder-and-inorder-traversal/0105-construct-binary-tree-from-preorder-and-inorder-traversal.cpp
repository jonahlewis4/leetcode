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
    unordered_map<int, int> inorderIdx;
    vector<int> preorder;
    vector<int> inorder;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        for(int i = 0; i < inorder.size(); i++){
            inorderIdx[inorder[i]] = i;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        int i = 0;
        i++;
        root->left = build(i, 0, inorderIdx[root->val] - 1);
        root->right = build(i, inorderIdx[root->val] + 1, inorder.size() - 1);
        return root;
    }
    TreeNode* build(int &i, int l, int r){
        if(i >= preorder.size() || inorderIdx[preorder[i]] < l || inorderIdx[preorder[i]] > r){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = build(i, l, inorderIdx[preorder[i - 1]] - 1);
        root->right = build(i, inorderIdx[preorder[i - 1]] + 1, r);
        return root;
    }
};