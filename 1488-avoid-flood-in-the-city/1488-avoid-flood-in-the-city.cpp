class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> drainings;
        unordered_map<int, int> lastRain;

        for(int i = 0; i < rains.size(); i++) {
            int lake = rains[i];
            if(lake == 0) {
                drainings.insert(i);
                continue;
            }

            //see if draining has occured since last rain
            rains[i] = -1;
            if(!lastRain.contains(lake)) {
                lastRain[lake] = i;
                continue;
            }

            set<int>::iterator it = drainings.lower_bound(lastRain[lake]);
            lastRain[lake] = i;
            if(it == drainings.end()) {
                return {};
            }
            int savingDrainIdx = *it;
            rains[savingDrainIdx] = lake;
            drainings.erase(it);
        }

        for(const int idx : drainings) {
            rains[idx] = 123456789;
        }
        return rains;

    }
};