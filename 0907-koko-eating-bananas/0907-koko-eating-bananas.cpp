class Solution {
private: 
    long long timeToEat(int speed, vector<int> & piles){
        long long time = 0;
        for(const auto & pile : piles){
            time += ceil((double)pile / speed);
        }
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int smallestPile = INT_MAX;
        int largestPile = INT_MIN;
        for(const int pile : piles){
            smallestPile = min(smallestPile, pile);
            largestPile = max(largestPile, pile);
        }

        int r = largestPile;
        int l = 1 ;

        int minSpeed = largestPile;

        while(l <= r){
            int mid = (l + r) / 2;
            long long time = timeToEat(mid, piles);

            if(time <= h){
                minSpeed = min(mid, minSpeed);
            } 
            if(time > h){
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return minSpeed;     

    }

};