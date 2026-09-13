class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int furthestHeater = 0;
        sort(heaters.begin(), heaters.end());
        for(const int house : houses) {
            //get first heater before the house
            int localDist = INT_MAX;
            vector<int>::iterator itr = lower_bound(heaters.begin(), heaters.end(), house);
            if(itr != heaters.begin()) {
                itr = prev(itr);
                int dist = house - *itr;
                localDist = min(dist, localDist);
            }
            itr = upper_bound(heaters.begin(), heaters.end(), house-1);

            if(itr != heaters.end()) {
                int dist = *itr - house;
                localDist = min(dist, localDist);
            }

            furthestHeater = max(furthestHeater, localDist);
        }

        return furthestHeater;
    }
};