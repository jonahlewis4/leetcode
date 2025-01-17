class Solution {
private:
    vector<int> *piles;
    long long timeToEat(int eatingSpeed){
        long long time = 0;
        for(const int i : *(this->piles)){
            time += ceil((double(i)) / eatingSpeed);
        }
        return time;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        this->piles = &piles;

        int l = 1;
        int r = *std::max_element(piles.begin(), piles.end()) ;

        int minEatingSpeed = INT_MAX;
        while(l <= r){
            int eatingSpeed = (l + r) / 2;
            long long timeToEat = this->timeToEat(eatingSpeed);
            if(timeToEat > h){
                l = eatingSpeed + 1;
            } else {
                minEatingSpeed = min(minEatingSpeed, eatingSpeed);
                r = eatingSpeed - 1;
            }   
        }   
        return minEatingSpeed;
    }
};