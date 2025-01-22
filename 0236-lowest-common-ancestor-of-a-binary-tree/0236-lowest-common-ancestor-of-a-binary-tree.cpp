/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto [ans, _, _] = dfs(root, p, q);
        return ans;
    }
    std::tuple<TreeNode*, bool, bool> dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return {nullptr, false, false};
        }
        bool pIsRoot = root == p;
        bool qIsRoot = root == q;

        if(qIsRoot && pIsRoot){
            return {root, true, true};
        }

        auto [lAns, lpFound, lqFound] = dfs(root -> left, p, q);
        if(lAns != nullptr){
            return {lAns, true, true};
        }
        auto [rAns, rpFound, rqFound] = dfs(root->right, p, q);
        if(rAns != nullptr){
            return {rAns, true, true};
        }

        if((pIsRoot || lpFound || rpFound) && (qIsRoot || lqFound || rqFound)){
            return {root, true, true};
        }

        return {nullptr, pIsRoot || lpFound || rpFound, qIsRoot || lqFound || rqFound};

    }
};