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
        cout<<"adding "<<val<<endl;        
        if(pq.size() < capacity){
            pq.push(val);
            cout<<"pushing 1"<<endl;
        } else if(val > pq.top()){
            int oldTop = pq.top();
            pq.pop();
            pq.push(val);
            cout<<"replacing "<<oldTop<<" with "<<val<<endl;
        }
        cout<<"returning smallest: "<<pq.top()<<endl;
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */