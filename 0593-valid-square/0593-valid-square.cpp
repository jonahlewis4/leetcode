class Solution {
    int len(vector<int>& p1, vector<int>& p2) {
        int side1 = (p1.front() - p2.front());
        int side2 = (p1.back() - p2.back());
        return side1 * side1 + side2 * side2;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> pts = {
            p1, p2, p3, p4
        };
        sort(pts.begin(), pts.end());

        int s1 = len(pts.front(), pts[1]);
        int s2 = len(pts.front(), pts[2]);
        int s3 = len(pts[1], pts[3]);
        int s4 = len(pts[2], pts[3]);

        int d1 = len(pts[1],pts[2]);
        int d2 = len(pts[0],pts[3]);

        return s1 == s2 && s2 == s3 && s3 == s4 && d1 == d2 && s1 > 0;

    }
};