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
    vector<int> in;
    unordered_map<int, int> postIdx;

    int inorderI(int l, int r, int search) const {
        for(int i = l; i <= r; i++) {
            if(in[i] == search) {
                return i;
            }
        }
        return -1;
    }
    int rightMostInPost(int l, int r) {
        int bestVal = in[l];
        for(int i = l + 1; i <= r; i++) {
            int val = in[i];
            if(postIdx[val] > postIdx[bestVal]){
                bestVal = val;
            }
        }
        return bestVal;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder;
        for(int i = 0; i < postorder.size(); i++) {
            postIdx[postorder[i]] = i;
        }

        int rootI = inorderI(0, inorder.size() - 1, postorder.back());
        return build(0, inorder.size() - 1);
    }

    TreeNode* build(int l, int r) {
        if(l > r) {
            return nullptr;
        }
        int rootVal = rightMostInPost(l, r);
        int rootI = inorderI(l, r, rootVal);

        TreeNode* root = new TreeNode(rootVal);
        root->right = build(rootI + 1, r);
        root->left = build(l, rootI - 1);
        return root;
    }
};