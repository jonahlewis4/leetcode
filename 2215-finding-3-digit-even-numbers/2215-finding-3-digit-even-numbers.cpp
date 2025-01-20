class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> digCount;
        for(const int i : digits){
            digCount[i]++;
        }
        vector<int> res;
        unordered_map<int, int> used;

        for(int i = 100; i <= 998; i+=2){
            int candidate = i;
            while(candidate > 0){
                used[candidate % 10]++;
                candidate /= 10;
            }

            bool gucci = true;
            for(const auto p : used){
                if(p.second > digCount[p.first]){
                    gucci = false;
                    break;
                }
            }
            if(gucci){
                res.push_back(i);
            }
            used.clear();
        }
        return res;
    }
};