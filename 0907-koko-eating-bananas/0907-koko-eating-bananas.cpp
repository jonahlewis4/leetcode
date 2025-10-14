class Solution {
    static long long eatingTime(const vector<int>& piles, int perHour){
        long long time  = 0;
        for(const int pile : piles) {
            int eatTime = ceil((double)pile / perHour);
            time += eatTime;
        }
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end());


        while(l <= r) {
            int m = (l + r) / 2;

            long long timeToEat = eatingTime(piles, m);

            if(timeToEat <= h) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};