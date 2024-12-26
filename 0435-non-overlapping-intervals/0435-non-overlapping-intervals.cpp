class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sort
        std::sort(intervals.begin(), intervals.end(), [](vector<int> &x, vector<int> &y){
            return x[0] < y[0];
        });
        
        //walk through while tracking the endPoint for overlapping
        //if we do not have an overlap, set the endPoint to the new one becausse it is a new interval
        //if we have an overlap, we 'delete' the one with the further endpoint because
        //we want to keep the one that extends less to the right and allows us to get away with less deletions.

        
        int end = intervals[0][1];
        int deletions = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < end){
                deletions++;
                end = min(end, intervals[i][1]);
            } else {
                end = intervals[i][1];
            }
        }
        return deletions;


    }
};