class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        std::priority_queue<int> pq;
        for(const int gift : gifts){
            pq.push(gift);
        }

        for(int i = 0; i < k; i++){
            int biggestGift = pq.top();
            pq.pop();

            int calculatedReduction = std::floor(std::sqrt(biggestGift));

            pq.push(calculatedReduction);
        }


        long long sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
        

    }
};