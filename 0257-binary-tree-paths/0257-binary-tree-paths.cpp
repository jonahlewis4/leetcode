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
    vector<string> paths;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return paths;
    }
    void dfs(TreeNode* root, string path){
        if(root == nullptr){
            return;
        }
        path += to_string(root->val);
        path += "->";
        if(root->left == nullptr && root->right == nullptr){
            path.pop_back();
            path.pop_back();
            paths.push_back(path);
        } else {
            dfs(root->left, path);
            dfs(root->right, path);
        }

    }
    
    
};