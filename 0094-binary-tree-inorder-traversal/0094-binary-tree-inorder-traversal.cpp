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
    TreeNode* rightMostInLeft(TreeNode* root) {
        TreeNode* predecessor = root->left;
        while(predecessor->right != nullptr && predecessor->right != root) {
            predecessor = predecessor->right;
        }
        return predecessor;
    }
vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* current = root;
        vector<int> res;
        while(current != nullptr) {
            if(current->left == nullptr) {
                res.push_back(current->val);
                current = current->right;
                continue;
            }     
            TreeNode* predecessor = rightMostInLeft(current);

            if(predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = nullptr;
                res.push_back(current->val);
                current = current->right;
                continue;
            }
        }
        return res;
    }
    
    
};