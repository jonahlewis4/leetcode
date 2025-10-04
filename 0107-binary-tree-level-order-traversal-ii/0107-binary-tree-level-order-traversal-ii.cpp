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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == nullptr) {
            return {};
        }
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            res.emplace_back();
            for(int i = 0; i < n; i++) {
                TreeNode* cur = q.front();
                q.pop();

                res.back().emplace_back(cur->val);

                if(cur->left != nullptr) {
                    q.push(cur->left);
                }
                if(cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};