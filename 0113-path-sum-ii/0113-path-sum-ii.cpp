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
    vector<vector<int>> res;
    vector<int> cur;
    int sum = 0;
    int target;

    static bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        r(root);


        return res;
    }
    void r(TreeNode* curNode) {
        if(curNode == nullptr) {
            return;
        }
        cur.push_back(curNode->val);
        sum += cur.back();
        if(sum == target && isLeaf(curNode)) {
            res.push_back(cur);
        }

        r(curNode->left);
        r(curNode->right);

        sum -= cur.back();
        cur.pop_back();

    }
};