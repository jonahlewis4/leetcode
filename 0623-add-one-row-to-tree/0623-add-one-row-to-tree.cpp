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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* res = new TreeNode(val);
            res->left = root;
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        for(int row = 1; row < depth - 1; row++) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }


        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            TreeNode* left = node->left;
            TreeNode* right = node->right;
            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            node->left->left = left;
            node->right->right = right;

        }

        return root;
    }
};