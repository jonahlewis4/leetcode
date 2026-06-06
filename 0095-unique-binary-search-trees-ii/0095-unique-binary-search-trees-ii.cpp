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
    vector<TreeNode*> getTrees(int min, int max) {
        
        if(max - min == 1) {
            return {nullptr};
        }
        vector<TreeNode*> res;

        for(int i = min + 1; i < max; i++){
            
            vector<TreeNode*> lefties = getTrees(min, i);
            vector<TreeNode*> righties = getTrees(i, max);

            for(TreeNode* lNode : lefties) {
                for(TreeNode* rNode : righties) {
                    TreeNode* center = new TreeNode(i);
                    center->left = lNode;
                    center->right = rNode;
                    res.push_back(center);
                }
            }


        }
        return res;

    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> trees = getTrees(0, n + 1);
    
        return trees;
    }
};