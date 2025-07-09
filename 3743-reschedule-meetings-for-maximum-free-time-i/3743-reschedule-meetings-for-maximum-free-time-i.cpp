class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps(startTime.size() + 1, 0);
        int lastEnd = 0;
        for(int i = 0; i < startTime.size(); i++) {
            int start = startTime[i];
            int gap = start - lastEnd;
            gaps[i] = gap;
            lastEnd = endTime[i]; 
        }
        gaps.back() = eventTime - lastEnd;

        int l = 0;
        int win = 0;
        for(int i = 0; i < k + 1; i++) {
            win += gaps[i];
        }


        int maxWin = win;
        while(l + k + 1 < gaps.size()){
            maxWin = max(win, maxWin);
            win -= gaps[l];
            win += gaps[l + k + 1];
            l++;
        }
        maxWin = max(maxWin, win);
        return maxWin;
    }
};