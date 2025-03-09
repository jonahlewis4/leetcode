class Solution {
private:
    const int maxTime = 1440;
    int diff(const int a, const int b) const {

        const int regularDiff = abs(a - b);
        const int rolloverDiff = abs(b + maxTime - a);
        // const int rolloverDiff2 = abs(time1 + maxTime - time2);

        return min({regularDiff, rolloverDiff});
    }
    int numerize(const string& a) const {
        int hours = (a[0] - '0') * 10 + (a[1] - '0');
        int minutes = (a[3] - '0') * 10 + (a[4] - '0');
        return hours * 60 + minutes;
    }
public:
    int findMinDifference(vector<string>& timePts) {
        std::vector<int> timePoints(timePts.size());
        for(int i = 0; i < timePts.size(); i++){
            timePoints[i] = numerize(timePts[i]);
        }
        sort(timePoints.begin(), timePoints.end());
        
        int minDiff = INT_MAX;
        int n = timePoints.size();
        timePoints.push_back(timePoints[0]);
        for(int i = 0; i < n; i++){
            minDiff = min(minDiff, diff(timePoints[i], timePoints[i + 1]));
        }
        return minDiff;
    }
};