class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& p1, const vector<int>& p2) {
            return p1.front() < p2.front();
        });

        int longest = 0;
        for(int i = 1; i < points.size(); i++) {
            int width = points[i].front() - points[i-1].front();
            longest = max(longest, width);
        }

        return longest;
    }
};