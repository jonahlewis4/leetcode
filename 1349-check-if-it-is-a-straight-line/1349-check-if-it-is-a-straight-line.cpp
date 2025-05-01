class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        struct point{
            int x;
            int y;
            float slope(const point &p2) const {
                if(x - p2.x == 0){
                    return numeric_limits<float>::infinity();
                }
                return float((y - p2.y)) * (x - p2.x);
            }
        };
        vector<point> points;
        for(const auto & coord : coordinates){
            int x = coord[0];
            int y = coord[1];
            points.push_back({
                .x = x,
                .y = y,
            });
        }

        float firstSlope = points[0].slope(points[1]); 

        for(int i = 2; i < points.size(); i++){
            if(points[i].slope(points[i - 1]) != firstSlope){
                return false;
            }
        }
        return true;

        
    }
};