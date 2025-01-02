class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::priority_queue<int, vector<int>, std::greater<int>> pq;
        for( const auto & num: nums){
            pq.push(num);
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};