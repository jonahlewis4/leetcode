class Solution {
private:
vector<int> sums;
public:
    Solution(vector<int>& w) {
        // sums.push_back(w[0]);
        // for(int i = 1; i < w.size(); i++){
        //     sums.push_back(w[i]);
        //     sums[i] += sums[i - 1];
        //     //cout<<sums[i]<<endl;
        // }
        for(auto n : w){
            sums.push_back(n + (sums.empty() ? 0 : sums.back()));
        }
    }
    
    int pickIndex() {
        float random = (float) rand() / RAND_MAX; 
        int randomNumber = random * sums.back();
        //cout<<"Random number: "<<randomNumber<<endl;
        //find entry where previous is less or equal current is greater. Return index of the greater one.

        return lower_bound(begin(sums), end(sums), randomNumber + 1) - begin(sums);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */