class Solution {
    bool possible(const vector<int>& citations, int h) {
        //get number smaller
        auto itr = upper_bound(citations.begin(), citations.end(), h - 1);
        //itr is first number >= h

        //count num elements BEFORE itr
        int numBefore = itr - citations.begin();

        int numWith = citations.size() - numBefore;
        return numWith >= h;

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