class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& c) {
        sort(g.begin(), g.end());
        sort(c.begin(), c.end());
        int cI = 0;
        int matches = 0;
        for(const auto & greed : g) {
            while(cI < c.size() && greed > c[cI]){
                cI++;
            }
            if(cI == c.size()) {
                break;
            }
            matches++;
            cI++;
        }
        return matches;
    }
};