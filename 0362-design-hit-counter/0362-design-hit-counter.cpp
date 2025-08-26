class HitCounter {
    deque<int> hits;
    public: 
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        hits.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        while(!hits.empty() && hits.front() <= timestamp - 300) {
            hits.pop_front();
        }
        return hits.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */