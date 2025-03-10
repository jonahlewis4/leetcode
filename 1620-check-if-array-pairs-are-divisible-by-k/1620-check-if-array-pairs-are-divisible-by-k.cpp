class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> rems(k, 0);
        for(const int i : arr){
            int remainder = i % k;
            if(remainder < 0){
                remainder = k + remainder;
            }
            rems[remainder]++;
        }

        int pairsFound = 0;
        int i = 0;
        while(pairsFound < arr.size() / 2){
            if(rems[i] == 0){
                i++;
                continue;
            }
            rems[i]--;
            int compliment = k - i;
            if(compliment == k){
                compliment = 0;
            }
            if(rems[compliment] == 0){
                return false;
            }
            rems[compliment]--;
            pairsFound++;
        }
        return true;
    }
};