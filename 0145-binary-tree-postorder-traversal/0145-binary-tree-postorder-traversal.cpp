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
    TreeNode* pred(TreeNode* root) {
        TreeNode* cur = root->left;
        while(cur->right != nullptr && cur->right != root) {
            cur = cur->right;
        }
        return cur;
    }
    void reverse(TreeNode* begin, TreeNode* end) {
        reverse(begin, end, [](TreeNode*){});
    }
    template <typename F>
    void reverse(TreeNode* begin, TreeNode* end, F onProcess){
        TreeNode* final = end->right;
        TreeNode* prev = nullptr;
        TreeNode* cur = begin;
        while(cur != final) {
            TreeNode* next = cur->right;
            cur->right = prev;
            prev = cur;
            onProcess(cur);
            cur = next;
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode sen;
        sen.left = root;
        TreeNode* senPtr = &sen;

        TreeNode* cur = senPtr;
        vector<int> ans;
        while(cur != nullptr) {
            if(cur->left == nullptr) {
                cur = cur->right;
            } else {
                TreeNode *predPtr = pred(cur);
                if(predPtr->right == cur) {
                    reverse(cur->left, predPtr);
                    reverse(predPtr, cur->left, [&ans](TreeNode* processed){
                        ans.push_back(processed->val);
                    });
                    predPtr->right = nullptr;
                    cur = cur->right;
                } else {
                    predPtr->right = cur;
                    cur = cur->left;
                }
            }
        }

        return ans;
    }
};