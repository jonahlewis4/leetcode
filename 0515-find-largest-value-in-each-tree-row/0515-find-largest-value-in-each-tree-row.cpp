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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        deque<TreeNode*> dq;
        dq.push_front(root);
        while(!dq.empty()){
            int n = dq.size();
            int largest = INT_MIN;
            for(int i = 0; i < n; i++){
                TreeNode* cur = dq.front();
                dq.pop_front();
                if(cur->left != nullptr){
                    dq.push_back(cur->left);
                }
                if(cur->right != nullptr){
                    dq.push_back(cur->right);
                }

                largest = max(largest, cur->val);
            }
            ans.push_back(largest);
        }
        return ans;
    }
};