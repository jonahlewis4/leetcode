class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] < b[0]){
                return true;
            } else if (a[0] == b[0]){
                return a[1] > b[1];
            }
            return false;
        });

        std::vector<int> lis;

        for(const auto & envelope : envelopes){
            auto pos = std::lower_bound(lis.begin(), lis.end(), envelope[1]);
            if(pos == lis.end()){
                lis.push_back(envelope[1]);
            } else {
                *pos = envelope[1];
            }
        }
        return lis.size();

    }
};