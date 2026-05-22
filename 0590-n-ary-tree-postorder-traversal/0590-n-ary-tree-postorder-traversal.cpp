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
    vector<int> postorder(const Node* const root) {
        if(!root) {
            return {};
        }
        vector<int> res;
        stack<const Node*> stk;
        stk.push(root);
        while(!stk.empty()) {
            const Node* const top = stk.top();
            stk.pop();
            for(const Node* const node : top->children) {
                stk.push(node);
            }

            res.push_back(top->val);

        }
        reverse(res.begin(), res.end());
        return res;
    }
};