class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max1I;
        int max2I;
        int min1I;
        int min2I;

        if(arrays.front().back() > arrays[1].back()) {
            max1I = 0;
            max2I = 1;
        } else {
            max1I = 1;
            max2I = 0;
        }
        if(arrays.front().front() < arrays[1].front()) {
            min1I = 0;
            min2I = 1;
        } else {
            min1I = 1;
            min2I = 0;
        }

        for(int i = 2; i < arrays.size(); i++) {
            int small = arrays[i].front();
            int big = arrays[i].back();

            if(big > arrays[max1I].back()) {
                max2I = max1I;
                max1I = i;
            } else if (big > arrays[max2I].back()) {
                max2I = i;
            }

            if(small < arrays[min1I].front()) {
                min2I = min1I;
                min1I = i;
            } else if (small < arrays[min2I].front()) {
                min2I = i;
            }
        }

        if(min1I != max1I) {
            return arrays[max1I].back() - arrays[min1I].front();
        }

        return max(
            arrays[max1I].back() - arrays[min2I].front(),
            arrays[max2I].back() - arrays[min1I].front()
        );
    }
};