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
public:
    Node* connect(Node* root) {
        if(root == nullptr) {
            return nullptr;
        }

        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            Node sen;
            Node* prev = &sen;
            for(int i = 0; i < n; i++) {
                Node* cur = q.front();
                q.pop();
                prev->next = cur;

                if(cur->left != nullptr) {
                    q.push(cur->left);
                }

                if(cur->right != nullptr) {
                    q.push(cur->right);
                }

                prev = cur;
            }
        }

        return root;
    }
};