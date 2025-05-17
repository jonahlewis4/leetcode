class LowerBound{
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;

        sub.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            //find first number >= num.
            auto lb = low_bound(sub.begin(), sub.end(), num);

            //if at the end push it back
            if(lb == sub.end()){
                sub.push_back(num);
            } else /*otherwise replace the one at that position with that value */ {
                int index = lb - sub.begin();
                sub[index] = num;
            }
        }

        return sub.size();
    }

    template <typename T>
    vector<T>::iterator low_bound(const vector<T>::iterator begin, const vector<T>::iterator end, T target) const{
        int l = begin - begin;
        int r = end - 1 - begin;

        auto smallest = end;
        while(l <= r) {
            int m = (l + r) / 2;
            auto midItr = begin + m;
            T midElement = *midItr;

            if(midElement >= target){
                if (smallest == end){
                    smallest = midItr;
                } else if(midElement < *smallest){
                    smallest = midItr;
                }
                r = m - 1;
            } else /*if midElement is smaller than the target, we need to visit larger value*/ {
                l = m + 1;
            }
        }
        return smallest;
    }
    
};

class Recursive{
public:
    int lengthOfLIS(vector<int>& nums) const {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res = max(res, recurse(i, nums));
        }
        return res;
    }

    int recurse(int i, const vector<int>& nums) const{
        if(i == 0){
            return 1;
        }       


        int res = 1;
        for(int j = i - 1; j >= 0; j--){
            if(nums[j] < nums[i]){
                int largestFromJ = recurse(j, nums);
                res = max(res, largestFromJ + 1);
            } 
        }
        return res;
    }

};

class Memo{
    vector<int> cache;
public:
    int lengthOfLIS(vector<int>& nums) {
        cache.resize(nums.size(), -1);
        
        for(int i = 0; i < nums.size(); i++){
            recurse(i, nums);
        }

        return *max_element(cache.begin(), cache.end());
    }

    int recurse(int i, const vector<int>& nums) {
        if(i == 0){
            cache[i] = 1;
            return cache[i];
        }       

        if(cache[i] != -1){
            return cache[i];
        }

        int res = 1;
        for(int j = i - 1; j >= 0; j--){
            if(nums[j] < nums[i]){
                int largestFromJ = recurse(j, nums);
                res = max(res, largestFromJ + 1);
            } 
        }
        cache[i] = res;
        return cache[i];
    }
};

class BottomUp {
    public:
    int lengthOfLIS(vector<int>& nums) const{
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
;
    }
};

class SegmentTreeSolution {
private:
    class SegmentTree{
    private:
        vector<int> nodes;
        int maxR;
        int _query(int qL, int qR, int tL, int tR, int treeIndex) const {
            //if tree within query return value

            if(tL >= qL && tR <= qR) {
                return nodes[treeIndex];
            }

            //if tree fully seperate reutrn int_min
            if((tL < qL && tR < qL) || (tL > qR && tR > qR)){
                return INT_MIN;
            }
            
            //if disjoint return max children

            int m = (tL + tR) / 2;
            int leftChild = _query(qL, qR, tL, m, treeIndex * 2 + 1);
            int rightChild = _query(qL, qR, m + 1, tR, treeIndex * 2 + 2);

            return max(leftChild, rightChild);
        }

        void _update(int matchI, int tL, int tR, int treeIndex, int newValue) {
            //if l == r and matchI, set and return;
            if(matchI == tL && matchI == tR){
                nodes[treeIndex] = newValue;
                return;
            }

            //move to the side that countains the matchI

            int m = (tL + tR) / 2;

            if(m >= matchI) /*if middle of tree parts is >= answer is on the left*/ {
                _update(matchI, tL, m, treeIndex * 2 + 1, newValue);
                nodes[treeIndex] = max(nodes[treeIndex], nodes[treeIndex * 2 + 1]);
            } else {
                _update(matchI, m + 1, tR, treeIndex * 2 + 2, newValue);
                nodes[treeIndex] = max(nodes[treeIndex], nodes[treeIndex * 2 + 2]);
            }
        }
    public:
        SegmentTree(int n){
            nodes.resize(n * 4, 0);
            maxR = n - 1;
        }
        int query(int l, int r) const {
            if(l > r){
                return 0;
            }

            return _query(l, r, 0, maxR, 0);
        }
        void update(int treeI, int newValue){
            _update(treeI, 0, maxR, 0, newValue); 
        }
    };
    class Ranker {
    private:
        unordered_map<int, int> ranks;
        const vector<int> &nums;
    public:
        Ranker(const vector<int> &nums) : nums(nums) {
            vector<int> values = nums;
            sort(values.begin(), values.end());


            int curRank = 0;
            ranks[values[0]] = curRank;
            curRank++;

            for(int i = 1; i < values.size(); i++){
                if(values[i] != values[i - 1]){
                    ranks[values[i]] = curRank;
                    curRank++;
                }
            }
        }

        int operator[](int i) const {
            return ranks.at(nums[i]);
        }

        int size() const {
            return ranks.size();
        }
    };

    



public:
    int lengthOfLIS(vector<int> &nums) {
        //create mapping of each index in nums to an index specifying it's rank
        Ranker treeI = Ranker(nums);
        SegmentTree tree(treeI.size());
        for(int i = 0; i < nums.size(); i++){
            //query to get the max in segment tree before treeI
            int maxPreceeding = tree.query(0, treeI[i] - 1);
            tree.update(treeI[i], maxPreceeding + 1);
        }

        return tree.query(0, treeI.size() - 1);

        
    }
};

class Solution {
    public:
    int lengthOfLIS(vector<int>& nums) {
        return SegmentTreeSolution().lengthOfLIS(nums);
    }
};