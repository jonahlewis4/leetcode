class Solution {
    int static dist(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        vector<int> p1 = {x,y};
        int bestI = -1;
        for(int i = 0; i < points.size(); i++) {
            const vector<int>& point = points[i];
            int px = point[0];
            int py = point[1];
            if(px == x || py == y) {
                int d = dist(p1, point);
                if(bestI == -1 || d < dist(p1, points[bestI])){
                    bestI = i;
                }
            }
        }   
        return bestI;
    }
};