class Solution {
private:
    class SegmentTree {
    private:
        vector<int> vals;
        vector<int> initial;
        vector<int> lazy;
        int n;
    int query(int segI, int queryL, int queryR, int segL, int segR) {
        //if fully disjoint return INT_MIN
        if(queryR < segL || segR < queryL) {
            return INT_MIN;
        }
        
        
        propogate(segI, segL, segR);
        //if query fully covers segment tree, return that value
        if(queryL <= segL && segR <= queryR){
            return vals[segI];
        }
        

        //else return result of left and right
        int m = (segL + segR) / 2;
        int res = INT_MIN;
        res = max(res, query(segI * 2 + 1, queryL, queryR, segL, m));
        res = max(res, query(segI * 2 + 2, queryL, queryR, m + 1, segR));
        return res;
    }

    void propogate(int segI, int segL, int segR){
        if(lazy[segI] != 0){
            vals[segI] += lazy[segI];
            if(segL != segR) {
                lazy[segI * 2 + 1] += lazy[segI];
                lazy[segI * 2 + 2] += lazy[segI];
            }
            lazy[segI] = 0;
        }
    }

    void RangeDecrease(int segI, int queryL, int queryR, int segL, int segR, int decreaseAmount){
        //if fully disjoint return immediately
        propogate(segI, segL, segR);

        auto& _lazy = lazy;
        auto& values = vals;
        if(queryR < segL || segR < queryL) {
            return; 
        }


        if(queryL <= segL && segR <= queryR) {
            lazy[segI] -= decreaseAmount;
            propogate(segI, segL, segR);
            return;
        }

        int m = (segL + segR) / 2;
        RangeDecrease(segI * 2 + 1, queryL, queryR, segL, m, decreaseAmount);
        RangeDecrease(segI * 2 + 2, queryL, queryR, m + 1, segR, decreaseAmount);
        vals[segI] = max(vals[2 * segI + 1], vals[2 * segI + 2]);


    }
    
    public:
        SegmentTree (const vector<int>& initial){
            n = initial.size();
            this->initial = initial;
            vals.resize(n * 4, 0);
            lazy.resize(n * 4, 0);
            fill(0, 0, n - 1);
        }    

        void fill(int segI, int queryL, int queryR) {
            if(queryL == queryR) {
                vals[segI] = initial[queryL];
                return;
            }
            int m = (queryL + queryR) / 2;
            fill(segI * 2 + 1, queryL, m);
            fill(segI * 2 + 2, m + 1, queryR);
            vals[segI] = max(vals[segI * 2 + 1], vals[segI * 2 + 2]);
        }

        int Query(int queryL, int queryR) {
            return query(0, queryL, queryR, 0, n - 1);
        }

        void RangeDecrease(int queryL, int queryR, int decreaseAmount){
            RangeDecrease(0, queryL, queryR, 0, n - 1, decreaseAmount);
        }
        
    };
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        SegmentTree tree(nums);
        int k = 0;
        while(true) {
            int q = tree.Query(0, nums.size() - 1);
            if(q <= 0){
                return k;
            }
            if(k >= queries.size()){
                return -1;
            }
            tree.RangeDecrease(queries[k][0], queries[k][1], queries[k][2]);
            k++;
        }

        return k;
    }

};