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
    bool valid = false;
    vector<int> arr;

public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        this->arr = arr;
        dfs(root, 0);
        return valid;
    }
    void dfs(TreeNode* root, int i){
        if(valid){
            return;
        }
        if(root == nullptr && i != arr.size()){
            return;
        }

        if(i >= arr.size()){
            return;
        } 

        auto cur = root;

        if(arr[i] != cur->val){
            return;
        }

        if(i == arr.size() - 1 && isLeaf(cur)) {
            valid = true;
            return;
        }

        dfs(root->left, i + 1);
        dfs(root->right, i + 1);
       

    }
    bool isLeaf(TreeNode* node){
        return !node->left && !node->right;
    }
};