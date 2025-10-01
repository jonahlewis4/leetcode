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
    unordered_map<int, int> valToInorderIdx;
    
    int postOrderI;
    vector<int> postOrder;
    vector<int> inOrder;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        inOrder = inorder;
        postOrder = postorder;
        for(int i = 0; i < inorder.size(); i++) {
            valToInorderIdx[inorder[i]] = i;
        }
        postOrderI = postorder.size() - 1;
        return build(0, inorder.size() - 1);
    }

    TreeNode* build(int l, int r) {
        if(l > r) {
            return nullptr;
        }

        int rootVal = postOrder[postOrderI];
        postOrderI--;

        TreeNode* newNode = new TreeNode(rootVal);
        int rootInorderIdx = valToInorderIdx[rootVal];

        newNode->right = build(rootInorderIdx + 1, r);
        newNode->left = build(l, rootInorderIdx - 1);

        return newNode;
    }
};