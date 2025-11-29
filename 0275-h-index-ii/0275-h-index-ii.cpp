class Solution {
    bool possible(const vector<int>& citations, int h) {
        int numFrom = citations.size() - h;
        if(h >= citations.size()) {
            return citations.front() >= h;
        }
        return citations[h] >= numFrom; 
    }
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int r = citations.size() - 1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            bool valid = possible(citations, mid);

            if(valid) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return citations.size() - l;
    }
};