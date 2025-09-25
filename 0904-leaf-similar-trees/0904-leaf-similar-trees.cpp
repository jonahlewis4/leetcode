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
    class LeafSum{
        TreeNode* base;
        vector<int> res = {};
        bool isLeaf(TreeNode* root) {
            return root->left == nullptr && root->right == nullptr;
        }
    public:
        LeafSum(TreeNode* root){
            base = root;
        }
        vector<int> Calc(){
            dfs(base);
            return res;
        }

        void dfs(TreeNode* cur) {
            if(cur == nullptr) {
                return;
            }
            if(isLeaf(cur)){
                res.push_back(cur->val);
                return;
            }

            dfs(cur->left);
            dfs(cur->right);
        }
    };
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1 = LeafSum(root1).Calc();
        vector<int> v2 = LeafSum(root2).Calc();
        if(v1.size() != v2.size()) {
            return false;
        }
        for(int i = 0; i < v1.size(); i++) {
            if(v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
};