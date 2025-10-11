class Solution {
    vector<pair<int, int>> counts;
    vector<long long> cache;
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> mp;
        for(const int i : power) {
            mp[i]++;
        }

        for(const auto & p : mp) {
            counts.push_back(p);
        }
        cache.resize(counts.size(), -1);
        return best(0);
    }

    long long best(int i) {
        const auto & c = counts;
        if(i >= counts.size()) {
            return 0;
        }

        if(cache[i] != -1) {
            return cache[i];
        }

        
        
        int thisVal = counts[i].first;
        long long bestChoice = (long long)thisVal * counts[i].second;
        for(int j = 1; j <= 3; j++) {
            int idx = i + j;
            if(idx >= counts.size()) {
                break;
            }

            int otherVal = counts[idx].first;
            if(otherVal <= thisVal + 2) {
                long long choice = best(idx);
                bestChoice = max(choice, bestChoice);
            } else {
                long long choice = thisVal * counts[i].second + best(idx);
                bestChoice = max(choice, bestChoice);
                break;
            }
        }
        cache[i] = bestChoice;
        return cache[i];
    }



    
};