class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
         //sort by start

        sort(points.begin(), points.end());

        //loop through points
        int firstEnd = points.front().back();
        int arrows = 0;
        for(const vector<int>& point : points) {
            //if a new point starts after the tracked point ends, throw an arrow
            if(point.front() > firstEnd) {
                //an arrow resets first end to the new point and increases number of arrows thrown
                arrows++;
                firstEnd = point.back();
            }

            firstEnd = min(point.back(), firstEnd);
        }
        return arrows + 1;
    }
};