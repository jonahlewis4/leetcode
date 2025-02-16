class LRUCache {
private:
    struct node{
        node* next;
        node* prev;
        int val;
        int key;
    };
    unordered_map<int, node*> map;
    int capacity;
    node* head;
    node* tail;

    void deleteTail(){
        if(tail == nullptr){
            return;
        } else if (tail->prev == nullptr){
            delete tail;
            tail = nullptr;
            head = nullptr;
        } else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }
    void insertHead(node* n){
        if(head == nullptr){
            head = n;
            tail = n;
            n->next = nullptr;
            n->prev = nullptr;
        } else {
            head->prev = n;
            n->next = head;
            n->prev = nullptr;
            head = n;
        }
    }
    void moveHead(node* n){
        if(n == head){
            return;
        } else if (n == tail){
            tail = tail->prev;
            tail->next = nullptr;
            insertHead(n);
        } else {
            n->prev->next = n->next;
            n->next->prev = n->prev;
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
            moveHead(map[key]);
            return map[key]->val;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key) == map.end()){
            node* newNode = new node{
                .next = nullptr,
                .prev = nullptr,
                .val = value,
                .key = key,
            };
            if(map.size() == capacity){
                map.erase(tail->key);
                deleteTail();
                insertHead(newNode);
            } else {
                insertHead(newNode);
            
            }
            map[key] = newNode;
        } else {
            map[key]->val = value;
            moveHead(map[key]);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */