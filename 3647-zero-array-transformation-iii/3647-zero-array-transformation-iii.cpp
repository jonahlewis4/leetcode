class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& _queries) {
        struct Query {
            int l;
            int r;
            bool operator<(const Query & other) const {
                if(l < other.l){
                    return true;
                }
                if(l > other.l){
                    return false;
                }

                if(r < other.r){
                    return true;
                }
                return false;
            }
        };
        


        vector<Query> queries;
        for(const auto & q : _queries){
            queries.push_back({
                .l = q[0],
                .r = q[1],
            });
        }

        sort(queries.begin(), queries.end());
        

        priority_queue<int> candidates;
        
        vector<int> queriesEndingBeforeHere(nums.size() + 1, 0);

        int queryIndex = 0;
        int activeQueries = 0;
        for(int i = 0; i < nums.size(); i++){
            activeQueries -= queriesEndingBeforeHere[i];

            while(queryIndex < queries.size() && queries[queryIndex].l == i){
                candidates.push(queries[queryIndex].r);
                queryIndex++;
            }

            while(!candidates.empty() && activeQueries < nums[i] && candidates.top() >= i){
                int top = candidates.top();
                candidates.pop();
                activeQueries++;
                queriesEndingBeforeHere[top + 1]++;
            }

            if(activeQueries < nums[i]){
                return -1;
            }
        }

        return candidates.size();

    }
};