/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    static vector<vector<int>> levelOrder(Node* root) {
        if(!root) {
            return {};
        }
        
        vector<vector<int>> res;
        queue<const Node*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> level;
            for(int i = 0; i < n; i++) {
                const Node* node = q.front();
                q.pop();

                for(const Node* const child: node->children) {
                    q.push(child);
                }
                level.push_back(node->val);
            }
            res.push_back(level);
        }

        return res;
    }
};