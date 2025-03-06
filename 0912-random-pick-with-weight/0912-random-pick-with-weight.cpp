class Solution {
private:
vector<int> sums;
int sum;
public:
    Solution(vector<int>& w) {
        int sum = 0;
        sums.push_back(w[0] - 1);
        sum += w[0];
        for(int i = 1; i < w.size(); i++){
            sums.push_back(w[i]);
            sums[i] += sums[i - 1];
            //cout<<sums[i]<<endl;
            sum += w[i];
        }
        //cout<<"sum: "<<sum<<endl;
        this->sum = sum;
    }
    
    int pickIndex() {
        int randomNumber = std::rand() % (sum);
        //cout<<"Random number: "<<randomNumber<<endl;
        //find entry where previous is less or equal current is greater. Return index of the greater one.
        
        int ans = -1;
        int l = 0; 
        int r = sums.size() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(sums[m] < randomNumber){
                l = m + 1;
            } else {
                ans = m;
                r = m - 1;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */