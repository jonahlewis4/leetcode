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
struct SizeNode : TreeNode {
public:
    int size = 1;
public:
    SizeNode(int val) : TreeNode(val){}
};
class Solution {
    vector<SizeNode*> getTrees(unordered_set<int>& values, int min, int max) {
        vector<SizeNode*> res{nullptr};

        for(int i = min + 1; i < max; i++){
            if(!values.contains(i)) {
                continue;
            }
            values.erase(i);
            
            vector<SizeNode*> lefties = getTrees(values, min, i);
            vector<SizeNode*> righties = getTrees(values, i, max);

            for(SizeNode* lNode : lefties) {
                for(SizeNode* rNode : righties) {
                    SizeNode* center = new SizeNode(i);
                    center->left = lNode;
                    center->right = rNode;
                    int lSize = lNode ? lNode->size : 0;
                    int rSize = rNode ? rNode->size : 0;
                    center->size = lSize + rSize + 1;
                    res.push_back(center);
                }
            }

            values.insert(i);
        }
        return res;

    }
public:
    vector<TreeNode*> generateTrees(int n) {
        unordered_set<int> values;
        for(int i = 1; i <= n; i++) {
            values.insert(i);
        }

        vector<SizeNode*> trees = getTrees(values, 0, n + 1);
        vector<TreeNode*> res;
        for(SizeNode* tree : trees) {
            if(tree && tree->size == n) {
                res.push_back(tree);
            }
        }
        return res;
    }
};