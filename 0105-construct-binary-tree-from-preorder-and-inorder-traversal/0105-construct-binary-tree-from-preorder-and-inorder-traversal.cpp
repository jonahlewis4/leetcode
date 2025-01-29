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
        for(int i = 0; i < this->inorder.size(); i++){
            inorderIdx[this->inorder[i]] = i;
        }   
        int i = 0;
        return build(0, inorder.size() - 1, i);

    }
    TreeNode* build(const int l, const int r, int & i){
        if(i >= preorder.size() || inorderIdx[preorder[i]] < l || inorderIdx[preorder[i]] > r ){
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(preorder[i]);
        i++;
        newNode->left = build(l, inorderIdx[newNode->val] - 1, i);
        newNode->right = build(inorderIdx[newNode->val] + 1, r, i);
        return newNode;
    }   
};