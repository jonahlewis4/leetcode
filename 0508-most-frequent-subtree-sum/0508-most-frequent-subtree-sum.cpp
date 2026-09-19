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
    unordered_map<int, int> map;
    int go(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        if(root->left || root->right) {
            int comb = root->val + go(root->left) + go(root->right);
            map[comb]++;
            return comb;
        } 
        map[root->val]++;
        return root->val;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        go(root);
        vector<int> res;
        for(const auto [key, value] : map) {
            if(res.empty()) {
                res.push_back(key);
                continue;
            }
            if(map[res.front()] < value){
                res.clear();
                res.push_back(key);
            } else if(map[res.front()] == value) {
                res.push_back(key);
            }
        }
        return res;
    }
};