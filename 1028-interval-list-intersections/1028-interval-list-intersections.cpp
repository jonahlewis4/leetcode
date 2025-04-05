class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        const auto cmp = [](const auto & a, const auto & b){
            return a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pqA;
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pqB;

        for(const auto & interval : firstList){
            pqA.push(interval);
        }
        for(const auto & interval : secondList){
            pqB.push(interval);
        }

        //if b starts after or equal  a and ends after or equal, there is overlap.
        //if a starts after or equal b and ends after, or equal,  there is overlap.


        //if there is overlap.
            //get the start of the one that ends second and the end of the one that ends first.
        
        
        //pop the one that ends first;
        vector<vector<int>> res;

        while(!pqA.empty() && !pqB.empty()){
            auto & endsFirst = pqA.top()[1] < pqB.top()[1] ? pqA : pqB;
            auto & startsSecond = pqA.top()[0] > pqB.top()[0] ? pqA : pqB;

            if(endsFirst.top()[1] - startsSecond.top()[0] >= 0){
                res.push_back({startsSecond.top()[0], endsFirst.top()[1]});
            }

            endsFirst.pop();
        }
        return res;

    }
};