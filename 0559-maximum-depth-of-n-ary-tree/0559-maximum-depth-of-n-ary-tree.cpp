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
    int _maxDepth = 0;
public:
    int maxDepth(Node* root) {
        explore(root, 1);
        return _maxDepth;
    }

    void explore(const Node* root, int depth){
        if(root == nullptr) {
            return;
        }

        _maxDepth = max(_maxDepth, depth);

        for(const Node* child : root->children) {
            explore(child, depth + 1);
        }
    }
};