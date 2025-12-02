class Solution {
    long long gaus(int n) {
        return ((long long)n * (n + 1)) / 2;
    }
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long numLines = 0;
        map<int, int> ptsAtY;
        for(const vector<int>& point : points) {
            int x = point.front();
            int y = point.back();

            ptsAtY[y]++;
        }

        for(const auto& [y, pts] : ptsAtY){
            numLines += gaus(pts - 1);
        }

        int MOD = (int)(1e9) + 7;
        int res = 0;

        for(const auto& [_, pts] : ptsAtY){
            int linesHere = gaus(pts - 1);
            numLines -= linesHere;
            res = (res + (numLines * linesHere) % MOD) % MOD;
        }

        return res;
    }
};