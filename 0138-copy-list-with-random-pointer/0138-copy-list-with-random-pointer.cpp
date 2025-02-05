/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        
        Node* cur = head;
        while(cur != nullptr){
            Node* next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }

        cur = head;
        Node* res = head->next;
        while(cur != nullptr){
            if(cur-> random == nullptr){
                cur->next->random = nullptr;
            } else {
                cur->next->random = cur->random->next;
            }
            Node* next = cur->next->next;
            cur = next;
        }

        cur = head;
        while(cur != nullptr){
            Node* next = cur->next->next;
            if(next != nullptr){
                cur->next->next = next->next;
            }
            cur->next = next;
            cur = cur->next;
        }
        return res;
    }
};