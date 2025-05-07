class Solution {
    class recursive{
        vector<int> cost;
    public:
        recursive(const vector<int> & _cost)  : cost(_cost){
        }
        int Solution() {
            this->cost.push_back(0);
            return recurse(cost.size() - 1);
        }
        int recurse(int n) const {
            if(n < 0){
                return INT_MAX; 
            }

            if(n == 0){
                return cost[0];
            }
            if(n == 1){
                return cost[1];
            }

            int oneStep = recurse(n - 1);
            int twoStep = recurse(n - 2);

            return cost[n] + min(oneStep, twoStep);
        }
    };
    class memo{
        vector<int> cache;
        const vector<int> &cost;
    public:
        memo(const vector<int> & _cost)  : cost(_cost){
            cache.resize(_cost.size() + 1, -1);
        }
        int Solution() {
            return recurse(cost.size());
        }
        int recurse(int n){
            if(n < 0){
                return INT_MAX; 
            }

            if(n == 0){
                return cost[0];
            }
            if(n == 1){
                return cost[1];
            }

            if(cache[n] != -1){
                return cache[n];
            }

            int oneStep = recurse(n - 1);
            int twoStep = recurse(n - 2);

            int curCost = n < cost.size() ? cost[n] : 0;
            int res = curCost + min(oneStep, twoStep);
            cache[n] = res;
            return res;
        }

    };

    class dp{
        public:
        const vector<int> &cost ;
        dp(const vector<int> & cost) : cost(cost) {

        }
        int Solution(){
            int twoAgo = cost[0];
            int oneAgo = cost[1];
            int cur;
            for(int i = 2; i <= cost.size(); i++){
                int curCost = i < cost.size() ? cost[i] : 0;
                cur = min(twoAgo, oneAgo) + curCost;
                twoAgo = oneAgo;
                oneAgo = cur;
            }
            return cur;
        }
    };
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return dp(cost).Solution();
    }
};