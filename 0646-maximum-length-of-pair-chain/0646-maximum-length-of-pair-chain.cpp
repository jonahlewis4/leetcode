class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& p1, const vector<int>& p2){
            return p1.back() < p2.back();
        });
        int chain = 1;
        int prevBack = pairs.front().back();
        for(int i = 1; i < pairs.size(); i++){
            vector<int>& cur = pairs[i];

            if(cur.front() <= prevBack) {
                continue;
            }
            chain++;
            prevBack = cur.back();
        }
        return chain;
    }
};