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
    TreeNode* predecessor(TreeNode* root) {
        TreeNode* cur = root->left;
        while(cur->right != root && cur->right != nullptr) {
            cur = cur->right;
        }
        return cur;
    }

    void reverse(TreeNode* begin, TreeNode* end) {
        return reverse(begin, end, [](TreeNode* cur){});
    }
    template <typename Func>
    void reverse(TreeNode* begin, TreeNode* end, Func onEach){
        TreeNode* cur = begin;
        TreeNode* prev = nullptr;
        while(cur != end) {
            onEach(cur);
            TreeNode* next = cur->right;
            cur->right = prev;
            prev = cur;
            cur = next;
        }
        cur->right = prev;
        onEach(cur);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        unique_ptr<TreeNode> sentinelWrap = make_unique<TreeNode>();
        TreeNode* sentinel = sentinelWrap.get();
        sentinel->left = root;

        TreeNode* cur = sentinel;
        vector<int> ans;

        while(cur != nullptr){
            if(cur->left == nullptr) {
                cur = cur->right;
                continue;
            }

            TreeNode* pred = predecessor(cur);
            if(pred->right == nullptr) {
                pred->right = cur;
                cur = cur->left;
            } else {
                reverse(cur->left, pred);
                reverse(pred, cur->left, [&ans](TreeNode* node){
                    ans.push_back(node->val);
                });
                cur = cur->right;
            }
        }
        return ans;
    }
};