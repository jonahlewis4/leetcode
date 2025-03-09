class Solution {
private:
    const int maxTime = 1440;
    int diff(const string& a, const string& b) const {
        const int time1 = numerize(a);
        const int time2 = numerize(b);

        const int regularDiff = abs(time1 - time2);
        const int rolloverDiff = abs(time2 + maxTime - time1);
        // const int rolloverDiff2 = abs(time1 + maxTime - time2);

        return min({regularDiff, rolloverDiff});
    }
    int numerize(const string& a) const {
        int hours = stoi(a.substr(0, 2));
        int minutes = stoi(a.substr(3, 2));
        return hours * 60 + minutes;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
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