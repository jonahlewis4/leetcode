class Solution {
private:
    int findLargestEnd(vector<vector<int>>& intervals){
        int largestEnd = intervals[0][1];
        for(const vector<int> & startEnd : intervals){
            largestEnd = max(largestEnd, startEnd[1]);
        }
        return largestEnd;
    }
    void incDec(vector<int> &counts, vector<vector<int>>& intervals){
        for(const vector<int> & startEnd : intervals){
            counts[startEnd[0]]++;
            counts[startEnd[1]]--;
        }
    }
    int maxPrefixSum(vector<int> &counts){
        int maxPrefix = counts[0];
        for(int i = 1; i < counts.size(); i++){
            counts[i] += counts[i - 1];
            maxPrefix = max(maxPrefix, counts[i]);
        }
        return maxPrefix;
    }



public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int largestEnd = findLargestEnd(intervals);
        vector<int> counts(largestEnd + 1);
        incDec(counts, intervals);
        return maxPrefixSum(counts);
    }
};