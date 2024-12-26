
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort into ascending order
        std::sort(intervals.begin(), intervals.end(), [](vector<int>& x, vector<int>& y) {
            return x[0] < y[0];
        });
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            //if previous and current overlap, merge them by 
            //setting the result to the merged.
            int n = result.size();
            if(intervals[i][0] <= result[n - 1][1]){
                int mergeStart = min(result[n - 1][0], intervals[i][0]);
                int mergeEnd = max(result[n - 1][1], intervals[i][1]);
                result[n - 1][0] = mergeStart;
                result[n - 1][1] = mergeEnd;
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};