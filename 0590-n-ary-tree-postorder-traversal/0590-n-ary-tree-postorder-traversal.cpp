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
        for(const Node* const node : root->children){
            vector<int> next = postorder(node);
            for(const int i : next) {
                res.push_back(i);
            }
        }
        res.push_back(root->val);
        return res;
    }
};