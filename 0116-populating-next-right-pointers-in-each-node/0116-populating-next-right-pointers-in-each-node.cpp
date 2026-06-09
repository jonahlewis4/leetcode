/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    
public:
    Node* connect(Node* root) {
        Node* top = root;
        while(top != nullptr) {
            bool onRight = false;
            Node sen;
            Node* prev = &sen;
            Node* nextTop = nullptr;
            while(top != nullptr) {
                Node* node = onRight ? top->right : top->left;
                
                if(node) {
                    prev->next = node;
                    prev = node;

                    if(!nextTop) {
                        nextTop = node;
                    }
                }
                
                if(onRight) {
                    top = top->next;
                }
                onRight = !onRight;
            }
            top = nextTop;
        }
        return root;
    }
};