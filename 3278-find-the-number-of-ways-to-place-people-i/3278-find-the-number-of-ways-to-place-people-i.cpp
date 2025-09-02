class Solution {
    class Points {
    public:
        struct Point{
            const int x = 0;
            const int y = 0;
            bool operator== (const Point& other) const {
                return other.x == x && other.y == y;
            }
        };
    private:

        vector<Point> pts;

        bool NegativeSlope(const Point& a, const Point& b) const {
            int run = b.x - a.x;

            if(run == 0) {
                return true;
            }
                        
            int rise = b.y - a.y;
            double slope = (double)rise / run;

            return slope <= 0;
        }
    public:
        Points(const vector<vector<int>>& incoming) {
            for(int i = 0; i < incoming.size(); i++) {
                pts.push_back(Point{
                    .x = incoming[i][0],
                    .y = incoming[i][1]
                });
            }
        }
        template <typename F>
        void ForAllPairs(F onEach) const{
            for(int i = 0; i < pts.size(); i++) {
                for(int j = i + 1; j < pts.size(); j++) {
                    onEach(pts[i], pts[j]);
                }
            }
        }

        bool CanRect(const Point& a, const Point& b) const {
            if(!NegativeSlope(a, b)){
                return false;
            }

            const Point& topLeft = TopLeft(a, b);
            const Point& botRight = BotRight(a, b);

            for(const auto & pt : pts) {
                if(pt == a || pt == b) {
                    continue;
                }
                if(pt.x >= topLeft.x && pt.x <= botRight.x
                    && pt.y <= topLeft.y && pt.y >= botRight.y){
                        return false;
                    }
            }
            return true;
        }

        const Point& TopLeft(const Point& a, const Point& b) const {
            if(a.x == b.x) {
                return a.y > b.y ? a : b;
            }
            return a.x < b.x ? a : b;
        }
        const Point& BotRight(const Point& a, const Point& b) const {
            if(a.x == b.x) {
                return a.y > b.y ? b : a;
            }
            return a.x > b.x ? a : b;
        }


        
    };

public:
    int numberOfPairs(vector<vector<int>>& points) {
        int numPairs = 0;
        const Points pts = Points(points);

        const auto & onEach = [&numPairs, &pts](const Points::Point& a, const Points::Point &b){
            if(pts.CanRect(a, b)){
                numPairs++;
            }
        };

        pts.ForAllPairs(onEach);

        return numPairs;
    }
};