class Solution {
vector<int> res;
TreeNode* rightMostInLeft(TreeNode* root) {
        TreeNode* predecessor = root->left;
        while(predecessor->right != nullptr && predecessor->right != root) {
            predecessor = predecessor->right;
        }
        return predecessor;
    }
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        while(cur != nullptr) {
            if(cur->left == nullptr) {
                res.push_back(cur->val);
                cur = cur->right;
                continue;
            }
            TreeNode* predecessor = rightMostInLeft(cur);
            if(predecessor->right == nullptr) {
                res.push_back(cur->val);
                predecessor->right = cur;
                cur = cur->left;
            } else {
                predecessor->right = nullptr;
                cur = cur->right;
            }
        }
        return res;
    }
};