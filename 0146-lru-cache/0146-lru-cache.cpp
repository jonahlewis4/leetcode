class LRUCache {
private:
    struct node {
        node* next;
        node* prev;
        int val;
        int key;
    };
    node* head;
    node* tail;

    unordered_map<int, node*> map;
    int capacity;


    void insertHead(node* n){
        if(head == nullptr){
            head = n;
            tail = n;
            n->next = nullptr;
            n->prev = nullptr;
        
        } else {
            head -> prev = n;
            n -> next = head;
            n->prev = nullptr;
            head = n;
        }
    }
    void deleteTail(){
        if(tail == nullptr){
            return;
        } else if (tail->prev != nullptr){
            tail = tail->prev;
            delete(tail->next);
            tail->next = nullptr;
        } else {
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        
    }
    void moveToFront(node* n){
        if(head == nullptr){
            insertHead(n);
        } else if (n == head){
            return;
        } else if (n -> next == nullptr){
            tail = n -> prev;
            n -> prev -> next = nullptr;
            insertHead(n);
        } else {
            n->prev -> next = n -> next;
            n -> next -> prev = n -> prev;
            insertHead(n);
        }
        
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()){
            return -1;
        } else {
            node* n = map[key];
            moveToFront(n);
            return n->val;
        }
    }
    
    void put(int key, int value) {
        if(get(key) == -1){
            if(map.size() + 1 > capacity){
                map.erase(tail->key);
                deleteTail();
            } 
            node* newNode = new node();
            newNode->val = value;
            newNode->key = key;
            insertHead(newNode);
            map[key] = newNode;
        } else {
            head->val = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */