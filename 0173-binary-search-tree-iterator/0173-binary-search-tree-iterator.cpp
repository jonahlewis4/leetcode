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
class BSTIterator {
    struct recursionSimulator{
        TreeNode* node;
        bool hasLeftBeenSearched;
    };
    std::stack<recursionSimulator> stack;
public:
    BSTIterator(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        stack.push({
            .node = root,
            .hasLeftBeenSearched = false,
        });
    }
    int next() {
        auto &_stack = stack;
        while(!stack.top().hasLeftBeenSearched){
            stack.top().hasLeftBeenSearched = true;
            if(stack.top().node->left != nullptr){
                stack.push({
                    .node = stack.top().node->left,
                    .hasLeftBeenSearched = false,
                });
            }
        }

        recursionSimulator top = stack.top();
        stack.pop();
        if(top.node->right != nullptr){
            stack.push({
                .node = top.node->right,
                .hasLeftBeenSearched = false,
            });
        }

        return top.node->val;
    }
    bool hasNext() {
        return !stack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */