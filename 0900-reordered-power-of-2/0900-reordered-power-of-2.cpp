class Solution {
private:
    static vector<unordered_map<int, int>> digitCounts;
    static vector<unordered_map<int, int>> calcdigits() {
        vector<unordered_map<int, int>> ans;
        int num = 1;
        for(int i = 0; i < 30; i++) {
            unordered_map<int, int> bset = getBitSet(num);
            num <<= 1;
            ans.push_back(bset);
        }
        return ans;
    }
    static unordered_map<int, int> getBitSet(int num) {
        unordered_map<int, int> bset;
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
        unordered_map<int, int> nBitSet = getBitSet(n);
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
vector<unordered_map<int, int>> Solution::digitCounts = Solution::calcdigits();