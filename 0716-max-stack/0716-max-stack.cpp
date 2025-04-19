class MaxStack {
    struct Node{
        int id;
        int val;
    };
    stack<Node> stack;
    priority_queue<Node, vector<Node>, decltype([](const auto & a, const auto & b){
        if(a.val < b.val){
            return true;
        }
        if(a.val == b.val){
            return a.id < b.id;
        }
        return false;
    })> pq;

    unordered_set<int> deleted;

    int nextId = 0;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        Node newNode{
            .id = nextId,
            .val = x
        };

        pq.push(newNode);
        stack.push(newNode);
        nextId++;
    }
    
    int pop() {
        cleanStack();
        int res = stack.top().val;
        deleted.insert(stack.top().id);
        stack.pop();
        return res;
    }
    
    int top() {
        cleanStack();
        return stack.top().val;
    }
    
    int peekMax() {
        cleanPq();
        return pq.top().val;
    }
    
    int popMax() {
        cleanPq();
        int toDelete = pq.top().val;
        deleted.insert(pq.top().id);
        pq.pop();
        return toDelete;
    }
    void cleanStack(){
    while(deleted.find(stack.top().id) != deleted.end()){
            stack.pop();
        }   
    }
    void cleanPq(){
        while(deleted.find(pq.top().id) != deleted.end()){
            pq.pop();
        }
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */