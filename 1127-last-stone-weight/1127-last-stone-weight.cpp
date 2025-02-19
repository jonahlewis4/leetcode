class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(const int stone : stones){
            pq.push(stone);
        }
        while(pq.size() > 1){
            int heaviest = pq.top();
            pq.pop();
            int secondHeaviest = pq.top();
            pq.pop();
            if(heaviest == secondHeaviest){
                continue;
            } else {
                pq.push(heaviest - secondHeaviest);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};