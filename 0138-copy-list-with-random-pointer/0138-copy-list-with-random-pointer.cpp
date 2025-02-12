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
        auto next = cur->next;
        cur->next = new Node(cur->val);
        cur->next->next = next;
        cur = next;
    }
    //printList(head);
    cur = head;

    while(cur != nullptr){
        if(cur->random == nullptr){
            cur->next->random = nullptr;
        } else {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }

    //printList(head);

    Node* newHead = head->next;
    cur = head;

    while(cur != nullptr){
        Node* next = cur->next;
        auto val = cur->val;

        if(cur->next != nullptr){
            cur->next = cur->next->next;
        } else {
            cur->next = nullptr;
        }
        cur = next;
    }
    return newHead;



}

void printList(Node* head){
    Node* cur = head;
    while(cur != nullptr){
        cout<<cur->val<<" ";
        cur = cur->next;
    }
    cout<<endl;
}
};