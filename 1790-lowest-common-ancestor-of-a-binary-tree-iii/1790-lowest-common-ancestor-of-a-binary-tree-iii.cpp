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
        int pDist = 0;
        int qDist = 0;
        Node* tempP = p;
        while(tempP != nullptr){
            tempP = tempP->parent;
            pDist++;
        }
        Node*tempQ = q;
        while(tempQ != nullptr){
            tempQ = tempQ->parent;
            qDist++;
        }
        int offset = abs(qDist - pDist);
        if(qDist > pDist){
            swap(p, q);
        }

        for(int i = 0; i < offset; i++){
            p = p->parent;
        }

        while(p != q){
            p = p->parent;
            q = q->parent;
        }
        return p;

    }
};