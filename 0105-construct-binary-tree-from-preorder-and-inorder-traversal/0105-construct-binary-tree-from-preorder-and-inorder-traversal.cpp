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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            this->inorderIdx[inorder[i]] = i;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); i++){
            TreeNode* cur = root;
            while(true){
                if(inorderIdx[preorder[i]] < inorderIdx[cur->val]){
                    if(cur->left == nullptr){
                        cur->left = new TreeNode(preorder[i]);
                        break;
                    } else {
                        cur = cur -> left;
                    }
                } else {
                    if(cur->right == nullptr){
                        cur->right = new TreeNode(preorder[i]);
                        break;
                    } else {
                        cur = cur -> right;
                    }
                }
            }   
            
        }
        return root;
    }
};