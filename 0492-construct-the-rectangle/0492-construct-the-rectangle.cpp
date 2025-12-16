class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = 1;
        int wRes;
        while(w * w <= area) {
            if(area % w != 0) {
                w++;
                continue;
            }
            wRes = w;
            w++;
        }

        return {area / wRes, wRes};
    }
};