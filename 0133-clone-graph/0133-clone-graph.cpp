/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
unordered_map<Node*, Node*> alreadyCopied;

public:
    Node* cloneGraph(Node* node) {
        Node* root = copy(node);
        return root;
    }
    Node* copy(Node* toCopy){
        if(toCopy == nullptr){
            return nullptr;
        }
        if(alreadyCopied.find(toCopy) != alreadyCopied.end()){
            return alreadyCopied[toCopy];
        }
        Node* newNode = new Node(toCopy->val);
        alreadyCopied[toCopy] = newNode;

        for(Node* const adj : toCopy->neighbors){
            newNode->neighbors.push_back(copy(adj));
        }
        return newNode;
    }
};