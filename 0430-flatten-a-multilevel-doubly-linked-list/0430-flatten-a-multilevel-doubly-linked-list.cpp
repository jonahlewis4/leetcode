/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
    Node* prev;
private:
    void flat(Node* head) {
        if(head == nullptr) {
            return;
        }
        prev->next = head;
        head->prev = prev;
        prev = head;

        Node* next = head->next;
        flat(head->child);
        head->child = nullptr;
        flat(next);
    }
public:
    Node* flatten(Node* head) {
        Node sen = Node();
        sen.next = head;
        prev = &sen;

        flat(head);
        if(head) head->prev = nullptr;
        return head;
    }
};