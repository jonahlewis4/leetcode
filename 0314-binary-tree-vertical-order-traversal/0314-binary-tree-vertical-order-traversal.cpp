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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        auto [lWide, rWide] = poles(root);
        
        int width = lWide + rWide - 1;
        int pivot = lWide - 1;
        vector<vector<int>> res(width);
        std::queue<tuple<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto[n, dst] = q.front();
                q.pop();
                res[dst + pivot].push_back(n->val);
                if(n->left != nullptr){
                    q.push({n->left, dst - 1});
                }
                if(n->right != nullptr){
                    q.push({n->right, dst + 1});
                }

            }
        }
        return res;
    }

    

    tuple<int, int> poles(const TreeNode* root){
        if(root == nullptr){
            return {0 , 0};
        }
        auto [ll, lr] = poles(root->left);
        ll++;
        lr--;
        auto [rl, rr] = poles(root->right);
        rl--;
        rr++;

        return {max(ll, rl), max(lr, rr)};

    }
};