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
private:
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, vector<pair<int, int>>> colRowVal;
        dfs(root, 0, 0, colRowVal);

        for(auto & col : colRowVal){
            sort(col.second.begin(), col.second.end(), [](auto & a, auto & b){
                return a.first < b.first || (a.first == b.first && a.second < b.second);
            });
        }

        vector<pair<int, vector<int>>> temp;
        for(auto & col : colRowVal){
            vector<int> vals(col.second.size());
            for(int i = 0; i < col.second.size(); i++){
                vals[i] = col.second[i].second;
            }
            temp.push_back({col.first, vals});
        }

        sort(temp.begin(), temp.end());
        vector<vector<int>> res(temp.size());
        for(int i = 0; i < temp.size(); i++){
            res[i] = temp[i].second;
        }
        return res;;
    }
    void dfs(TreeNode* root, int r, int c, unordered_map<int, vector<pair<int, int>>>& colRowVal){
        if(root == nullptr){
            return;
        }
        colRowVal[c].push_back({r, root->val});
        dfs(root->left, r + 1, c - 1, colRowVal);
        dfs(root->right, r + 1, c + 1, colRowVal);
    }
};