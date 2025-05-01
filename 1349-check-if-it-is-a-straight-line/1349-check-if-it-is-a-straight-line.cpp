class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        struct point{
            int x;
            int y;
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

        int x0 = points[0].x;
        int y0 = points[0].y;

        int x1 = points[1].x;
        int y1 = points[1].y;

        //make sure all incoming ones match this equation.

        int deltaX1 = x1 - x0;
        int deltaY1 = y1 - y0; 


        for(int i = 2; i < points.size(); i++){
            //if delta y1 / delta x1 = delta y2 / delta x2 its ok
            //same as deltax1 * deltay2 = deltay1 * dletax2

            int x2 = points[i].x;
            int y2 = points[i].y;

            int deltaX2 = x2 - x0;
            int deltaY2 = y2 - y0;

            if(deltaX1 * deltaY2 != deltaY1 * deltaX2){
                return false;
            }
        }
        return true;

        
    }
};