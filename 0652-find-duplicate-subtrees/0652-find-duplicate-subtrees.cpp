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
    unordered_map<string, TreeNode*> map;
    string r(TreeNode* root) {
        if(root == nullptr) {
            return "";
        }

        string left = r(root->left);
        string right = r(root->right);
        string serialization = to_string(root->val)+"l"+left+"r"+right;
        if(!map.contains(serialization)){
            map[serialization] = nullptr;
        } else {
            map[serialization] = root;
        }

        return serialization;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        r(root);

        vector<TreeNode*> res;
        for(const auto [_, node] : map){
            if(node){
                res.push_back(node);
            }
        }

        return res;
    }
};