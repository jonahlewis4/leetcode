class Solution {
    double dist(const vector<int>& a, const vector<int>& b) {
        int d1 = a[0] - b[0];
        int d2 = a[1] - b[1];
        int sum = d1 * d1 + d2 * d2;
        return sqrt(sum);
    }
    double areaOf(double a, double b, double c) {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }   

    
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                for(int k = j + 1; k < points.size(); k++){
                    const vector<int>& p1 = points[i];
                    const vector<int>& p2 = points[j];
                    const vector<int>& p3 = points[k];

                    double d1 = dist(p1, p2);
                    double d2 = dist(p2, p3);
                    double d3 = dist(p3, p1);

                    double area = areaOf(d1, d2, d3);
                    if(area > maxArea) {
                        maxArea = area;
                    }
                }
            }
        }
        return maxArea;
    }
};