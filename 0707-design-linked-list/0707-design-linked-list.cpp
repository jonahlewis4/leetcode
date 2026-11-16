class MyLinkedList {
    struct Node{
        int val;
        Node* next = nullptr;

        Node(int val){
            this->val = val;
        }
    };

    int size = 0;
    Node sen = Node(0);
public:
    MyLinkedList() {
    }

    Node* getNode(int index) {
        Node* cur = &sen;
        for(int i = 0; i <= index; i++) {
            cur = cur->next;
        }
        return cur;
    }
    
    int get(int index) {
        if(index >= size) {
            return -1;
        }

        return getNode(index)->val;
    }
    
    void addAtHead(int val) {
        Node* head = sen.next;
        sen.next = new Node(val);
        sen.next->next = head;
        size++;
    }
    
    void addAtTail(int val) {
        Node* tail = getNode(size - 1);
        tail->next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index == size) {
            addAtTail(val);
            return;
        }
        if(index > size) {
            return;
        }
        Node* before = getNode(index - 1);
        Node* oldNext = before->next;
        before->next = new Node(val);
        size++;
        before->next->next = oldNext;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) {
            return;
        }
        Node* before = getNode(index - 1);
        Node* oldNext = before->next;
        before->next = oldNext->next;
        delete oldNext;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */