class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;
        for(int i = 0; i + 1 < points.size(); i++) {
            const vector<int>& currentPoint = points[i];
            const vector<int>& nextPoint = points[i + 1];

            int deltaY = nextPoint[1] - currentPoint[1];
            int deltaX = nextPoint[0] - currentPoint[0];

            int deltaDelta = abs(deltaY-deltaX);
            cout<<deltaDelta<<endl;
            int nonOptimals = max(abs(deltaY), abs(deltaX)) - deltaDelta;
            cout<<nonOptimals<<endl;
            totalTime += deltaDelta + nonOptimals;
        }

        return totalTime;
    }
};