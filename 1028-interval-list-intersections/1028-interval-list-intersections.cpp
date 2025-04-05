class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        

        //if b starts after or equal  a and ends after or equal, there is overlap.
        //if a starts after or equal b and ends after, or equal,  there is overlap.


        //if there is overlap.
            //get the start of the one that ends second and the end of the one that ends first.
        
        
        //pop the one that ends first;
        vector<vector<int>> res;

        int i = 0;
        int j = 0;
        
        // while(!pqA.empty() && !pqB.empty()){
        //     auto & endsFirst = pqA.top()[1] < pqB.top()[1] ? pqA : pqB;
        //     auto & startsSecond = pqA.top()[0] > pqB.top()[0] ? pqA : pqB;

        //     if(endsFirst.top()[1] - startsSecond.top()[0] >= 0){
        //         res.push_back({startsSecond.top()[0], endsFirst.top()[1]});
        //     }

        //     endsFirst.pop();
        // }

        while(i < firstList.size() && j < secondList.size()){
            auto & endsFirst = firstList[i][1] < secondList[j][1] ? firstList : secondList;
            int &endFirstIdx = &endsFirst == &firstList ? i : j;
            auto & startsSecond = firstList[i][0] > secondList[j][0] ? firstList : secondList;
            int startSecondIdx = &startsSecond == &firstList ? i : j;

            if(endsFirst[endFirstIdx][1] - startsSecond[startSecondIdx][0] >= 0){
                res.push_back({startsSecond[startSecondIdx][0], endsFirst[endFirstIdx][1]});
            }

            endFirstIdx++;
        }


        return res;

    }
};