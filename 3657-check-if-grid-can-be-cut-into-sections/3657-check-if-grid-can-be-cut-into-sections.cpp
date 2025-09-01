class Solution {
    class Checker {
        struct Interval {
            int start = 0;
            int end = 0;
        };
    public:

        vector<Interval> intervals;
        Checker(const vector<vector<int>>& rects, bool vertical){
            for(const auto & rect : rects) {
                int start = rect[0 + vertical];
                int end = rect[2 + vertical];

                intervals.push_back({
                    .start = start,
                    .end = end
                });
            }
        }

        bool Check() {
            vector<Interval>& startCopy = intervals;
            sort(startCopy.begin(), startCopy.end(), [](const Interval& a, const Interval& b){
                return a.start < b.start;
            });
            
            Interval ivl = startCopy[0];
            int cuts = 0;
            for(const auto & newIvl : startCopy){
                if(newIvl.start >= ivl.end){
                    cuts++;
                    if(cuts == 2){
                        return true;
                    }
                    ivl = newIvl;
                } else if (newIvl.end > ivl.end) {
                    ivl.end = newIvl.end;
                }
            }
            return false;
        }
    };

public:
    static bool checkValidCuts(int n, const vector<vector<int>>& rectangles) {
        bool horiSliceable = Checker(rectangles, false).Check();
        if(horiSliceable) {
            return true;
        }
        bool vertiSliceable = Checker(rectangles, true).Check();
        return vertiSliceable;
    }
};