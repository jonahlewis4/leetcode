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
    TreeNode* firstDecrease = nullptr;
    TreeNode* secondDecrease = nullptr;
    TreeNode* firstPrev = nullptr;
    TreeNode* prev = nullptr;
    void r(TreeNode*const root) {
        if(!root) {
            return;
        }
        r(root->left);
        if(prev != nullptr && prev->val > root->val){
            if(firstDecrease) {
                secondDecrease = root;
                return;
            } else {
                firstDecrease = root;
                firstPrev = prev;
            }
        }
        cout<<root->val<<endl;
        prev = root;
        r(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        

        r(root);
        if(!secondDecrease) {
            swap(firstDecrease->val, firstPrev->val);
        } else {
            swap(firstPrev->val, secondDecrease->val);
        }

    }
};