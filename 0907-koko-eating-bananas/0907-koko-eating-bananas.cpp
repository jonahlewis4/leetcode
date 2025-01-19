class Solution {
private:
    long long timeToEat(vector<int>& piles, int eatingSpeed){
        long long sum = 0;
        for(const auto & pile : piles){
            sum += std::ceil(double(pile) / eatingSpeed);
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());


        int minEating = INT_MAX;
        while( l <= r){
            int m = (l + r) / 2;
            long long eatingTime = timeToEat(piles, m);

            if(eatingTime <= h){
                minEating = std::min(minEating, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return minEating;

    }
};