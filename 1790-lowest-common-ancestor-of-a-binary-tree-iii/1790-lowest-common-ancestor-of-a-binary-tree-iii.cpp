/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        std::unordered_set<Node*> pSet;
        std::unordered_set<Node*> qSet;
        while(true){
            pSet.insert(p);
            if(pSet.find(q) != pSet.end()){
                return q;
            }
            qSet.insert(q);
            if(qSet.find(p) != qSet.end()){
                return p;
            }
            q = !q ? q : q->parent;
            p = !p ? p : p->parent;
        }
        return nullptr;
    }
};