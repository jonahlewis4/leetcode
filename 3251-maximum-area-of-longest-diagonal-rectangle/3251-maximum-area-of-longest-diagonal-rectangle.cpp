class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int bestDiag = 0;
        int bestArea = 0;
        for(const auto & rectangle : dimensions) {
            int l = rectangle[0];
            int r = rectangle[1];
            int diag = l * l + r * r;
            if(diag > bestDiag) {
                bestDiag = diag;
                bestArea = l * r;
            } else if (diag == bestDiag) {
                bestArea = max(bestArea, l * r);
            }
        }
        return bestArea;
    }
};