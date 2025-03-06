class Solution {
private:
vector<int> sums;
int sum;
public:
    Solution(vector<int>& w) {
        sums = w;
        int sum = 0;
        for(const int i : w){
            sum += i;
        }
        this->sum = sum;
    }
    
    int pickIndex() {
        int randomNumber = std::rand() % (sum);
        int i = 0;
        while(randomNumber >= 0){
            randomNumber -= sums[i];
            i++;
        }
        return i - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */