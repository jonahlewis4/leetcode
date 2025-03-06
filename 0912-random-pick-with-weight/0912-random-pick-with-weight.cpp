class Solution {
private:
vector<int> sums;
int sum;
public:
    Solution(vector<int>& w) {
        sums = w;
        int sum = 0;
        sums[0] = w[0];
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
        for(int i = 0; i < sums.size(); i++){
            if(sums[i] > randomNumber){
                return i;
            }
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */