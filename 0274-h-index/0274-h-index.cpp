class Solution {
    bool possible(const vector<int>& citations, int h) {
        int reached = 0;
        for(const int i : citations) {
            if(i < h){
                continue;
            }
            reached++;
            if(reached >= h) {
                return true;
            }
        }

        return false;
    }
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int r = citations.size();

        while(l <= r) {
            int mid = l + (r - l) / 2;
            bool valid = possible(citations, mid);

            if(valid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return r;
    }
};