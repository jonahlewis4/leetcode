class Solution {
    static inline int area(int x1, int y1, int x2, int y2) {
        return (x2 - x1) * (y2 - y1);
    }
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int l = max(ax1, bx1);
        int r = min(ax2, bx2);

        int t = min(ay2, by2);
        int b = max(ay1, by1);


        int overlap = max((r - l), 0) * max(0, (t - b));

        int area1 = area(ax1, ay1, ax2, ay2);
        int area2 = area(bx1, by1, bx2, by2);

        return area1 + area2 - overlap;
        
    }
};