class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> topHalf;
    priority_queue<int> bottomHalf;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(topHalf.empty()){
            if(bottomHalf.empty() || num > bottomHalf.top()){
                topHalf.push(num);
            } else {
                bottomHalf.push(num);
            }
        } else if (bottomHalf.empty()){
            if(topHalf.empty() || num < topHalf.top()){
                bottomHalf.push(num);
            } else {
                topHalf.push(num);
            }
        } else if(num > topHalf.top()){
            topHalf.push(num);
        } else {
            bottomHalf.push(num);
        }

        if(topHalf.size() > bottomHalf.size() + 1){
            bottomHalf.push(topHalf.top());
            topHalf.pop();
        } else if(bottomHalf.size() > topHalf.size() + 1){
            topHalf.push(bottomHalf.top());
            bottomHalf.pop();
        }
    }
    
    double findMedian() {
        if(topHalf.size() > bottomHalf.size()){
            return topHalf.top();
        } else if (bottomHalf.size() > topHalf.size()){
            return bottomHalf.top();
        } else {
            return ((double)topHalf.top() + (double)bottomHalf.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */