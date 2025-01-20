class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> digCount;
        for(const int i : digits){
            digCount[i]++;
        }
        vector<int> res;
        for(int i = 100; i <= 998; i+=2){
            unordered_map<int, int> used;
            int candidate = i;
            if(digCount[candidate % 10] <= used[candidate % 10]){
                continue;
            }
            used[candidate % 10]++;
            candidate /= 10;
            if(digCount[candidate % 10] <= used[candidate % 10]){
                continue;
            }
            used[candidate % 10]++;
            candidate /= 10;
            if(digCount[candidate % 10] <= used[candidate % 10]){
                continue;
            }
            res.push_back(i);
        }
        return res;
    }
};