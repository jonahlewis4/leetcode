class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        std::unordered_map<int, int> before;
        std::unordered_map<int, int> after;

        int furthestPipe = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '|'){
                furthestPipe = i;
            }
            before[i] = furthestPipe;
            
        }

        int leftMostPipe = s.size();
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '|'){
                leftMostPipe = i;
            } 
            after[i] = leftMostPipe;

        }

        vector<int> prefixSum(s.size(), 0);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                prefixSum[i]++;
            }
            if(i > 0){
                prefixSum[i] += prefixSum[i - 1];
            }
        }
        vector<int> ans(queries.size(), 0);
        for(int i = 0; i < queries.size(); i++){
            const vector<int>& query = queries[i];
            int leftMost = after[query[0]];
            int rightMost = before[query[1]];
            if(leftMost >= rightMost){
                continue;
            }
            ans[i] = prefixSum[rightMost] - prefixSum[leftMost];

        }
        return ans;
    }
};