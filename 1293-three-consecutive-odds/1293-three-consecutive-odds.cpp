class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool twoAgo = false;
        bool oneAgo = false;
        for(const auto & num : arr) {
            if(num % 2 == 1) {
                if(oneAgo && twoAgo) {
                    return true;
                }
            }
            twoAgo = oneAgo;
            oneAgo = num % 2 == 1;
        }
        return false;
    }
};