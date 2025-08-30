class Solution {
    class Sol {
    private:
        const vector<int>& _nums;
        vector<vector<int>> _res;
        unordered_map<int, int> counts;
        vector<int> _cur;

        //only call this once in the constructor
        void computeRes(){
            backtrack(0);
        }
        void backtrack(int i) {
            if(i == _nums.size()) {
                _res.push_back(_cur);
            }

            for(auto & itr : counts) {
                if(itr.second == 0) {
                    continue;
                }
                itr.second--;
                _cur.push_back(itr.first);
                backtrack(i + 1);
                _cur.pop_back();
                itr.second++;
            }

            
        }
    public:
        Sol(const vector<int>& nums) : _nums(nums){
            for(const auto & num : _nums) {counts[num]++;}
            computeRes();
        }
        vector<vector<int>> GetRes() const {
            return _res;
        }
    };
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        return Sol(nums).GetRes();
        
    }
};