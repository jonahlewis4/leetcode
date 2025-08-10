class Solution {
private:
    static vector<vector<int>> digitCounts;
    static vector<vector<int>> calcdigits() {
        vector<vector<int>> ans;
        int num = 1;
        for(int i = 0; i < 30; i++) {
            vector<int> bset = getBitSet(num);
            num <<= 1;
            ans.push_back(bset);
        }
        return ans;
    }
    static vector<int> getBitSet(int num) {
        vector<int> bset(10, 0);
        int numCopy = num;
        while(numCopy > 0) {
            int digit = numCopy % 10;
            bset[digit]++;
            numCopy /= 10;
        }
        return bset;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<int> nBitSet = getBitSet(n);
        for(auto & twoPowerBSet : digitCounts) {
            bool match = true;
            for(int i = 0; i <= 9; i++){
                if(twoPowerBSet[i] != nBitSet[i]){
                    match = false;
                    break;
                }
            }
            if(match) {
                return true;
            }
        }
        return false;
    }
}; 
vector<vector<int>> Solution::digitCounts = Solution::calcdigits();