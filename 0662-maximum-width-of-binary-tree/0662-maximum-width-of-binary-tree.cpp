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
    vector<int> leftMostIdxAtRow;
    int best = 0;
    void recurse(TreeNode* root, int depth, long long i){
        if(root == nullptr){
            return;
        }

        if(leftMostIdxAtRow.size() == depth){
            leftMostIdxAtRow.push_back(i);
        }

        int leftMost = leftMostIdxAtRow[depth];
        int width = i - leftMost + 1;
        best = max(best, width);

        i = i - leftMost;

        recurse(root->left, depth+1, i*2+1);
        recurse(root->right, depth+1, i*2+2);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        recurse(root, 0, 0);
        return best;
    }
};