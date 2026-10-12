class Solution {
    double radius;
    double x_center;
    double y_center;
public:
    Solution(double radius, double x_center, double y_center) : radius(radius), x_center(x_center), y_center(y_center){
        
    }
    
    vector<double> randPoint() {
        double newRadius = sqrt((double)rand() / INT_MAX) * radius;
        double angle = (M_PI * 2) * rand() / INT_MAX;

        double xDelta = newRadius * cos(angle);
        double yDelta = newRadius * sin(angle);

        double x = x_center + xDelta;
        double y = y_center + yDelta;

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */