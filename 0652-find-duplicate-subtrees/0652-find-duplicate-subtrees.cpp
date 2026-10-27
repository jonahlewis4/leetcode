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
    unordered_map<string, int> tripletToId;
    unordered_map<int, TreeNode*> idToRoot;
    int currentId = 1;
    int r(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int left = r(root->left);
        int right = r(root->right);
        string serialization = to_string(root->val)+"l"+to_string(left)+"r"+to_string(right);
        
        auto itr = tripletToId.find(serialization);
        int id;
        if(itr == tripletToId.end()){
            id = tripletToId[serialization] = currentId;
            currentId++;
        } else {
            id = itr->second;
        }

        auto itr2 = idToRoot.find(id);
        if(itr2 == idToRoot.end()){
            idToRoot[id] = nullptr;
        } else {
            itr2->second = root;
        }

        return id;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        r(root);

        vector<TreeNode*> res;
        for(const auto [_, node] : idToRoot){
            if(node){
                res.push_back(node);
            }
        }

        return res;
    }
};