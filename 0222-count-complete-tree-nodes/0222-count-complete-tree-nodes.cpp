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
    int _height = 0;
    static int lDist(TreeNode* root) {
        TreeNode* left = root->left;
        int dist = 1;
        while(left != nullptr) {
            left = left->right;
            dist++;
        }
        return dist;
    }
    static int height(TreeNode* root) {
        int dist = 0;
        while(root != nullptr) {
            root = root->left;
            dist++;
        }
        return dist;
    }
public:
    int countNodes(TreeNode* root) {
        _height = height(root);
        if(_height == 0) {
            return 0;
        }
        if(_height == 1) {
            return 1;
        }
        int offset = recurse(root, 0);
        return (1 << (_height - 1)) + offset;

        
    }
    int recurse(TreeNode* root, int depth) {
        if(depth == _height - 1) {
            return 0;
        }
        if(root->left == nullptr) {
            return -1;
        }
        if(root->right == nullptr) {
            return 0;
        }
    
        int leftHeight = lDist(root) + depth;
        if(leftHeight == _height) {
            int skipped = (1 << (_height - depth - 2));
            int skippLeft = recurse(root->right, depth + 1);
            return skipped + skippLeft;
        } else {
            return recurse(root->left, depth + 1);
        }

        return 0;
    }
};