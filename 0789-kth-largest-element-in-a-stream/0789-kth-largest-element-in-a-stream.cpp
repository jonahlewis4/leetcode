class KthLargest {
    private:
    priority_queue<int, vector<int>, std::greater<int>> pq;
    int capacity;
public:
    KthLargest(int k, vector<int>& nums) {
        capacity = k;

        for(int i = 0; i < nums.size(); i++){
            if(pq.size() != capacity){
                pq.push(nums[i]);
            } else {
                add(nums[i]);
            }
        }

    }
    
    int add(int val) {
        if(pq.size() < capacity){
            pq.push(val);
        } else if(val > pq.top()){
            int oldTop = pq.top();
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */