class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int d1 = points[1][1] - points[0][1];
        int d2 = points[2][0] - points[1][0];

        int d3 = points[2][1] - points[1][1];
        int d4 = points[1][0] - points[0][0];

        bool inLine = d1 * d2 == d3 * d4;

        bool areSame1 = points[0] == points[1];
        bool areSame2 = points[1] == points[2];
        bool areSame3 = points[0] == points[2];

        return !inLine && !areSame1 && !areSame2 && !areSame3;
    }
};