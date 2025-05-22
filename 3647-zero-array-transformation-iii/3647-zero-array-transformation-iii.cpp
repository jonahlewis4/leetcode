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
        priority_queue<int, vector<int>, greater<int>> chosen;

        int queryI = 0;
        int i = 0;

        int migrations = 0;

        while(i < nums.size()){
            while(!chosen.empty() && chosen.top() < i){
                chosen.pop();
            }   

            while(queryI < queries.size() && queries[queryI].l == i){
                candidates.push(queries[queryI].r);
                queryI++;
            }


            nums[i] -= chosen.size();
            
            while(nums[i] > 0 && !candidates.empty()){
                if(candidates.top() < i){
                    candidates.pop();
                    continue;
                }
                migrations++;
                chosen.push(candidates.top());
                nums[i]--;
                candidates.pop();
            }
            

            if(nums[i] > 0) {
                return -1;
            }
            i++;
        } 

        return queries.size() - migrations;


    }
};