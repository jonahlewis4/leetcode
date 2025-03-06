class Solution {
private:
vector<int> sums;
int sum;
int total0;
int total1;
int total2;
int total3;
int totalPicks;
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
        total0 = 0;
        total1 = 0;
        total2 = 0;
        total3 = 0;
        totalPicks = 0;
    }
    
    int pickIndex() {
        totalPicks++;
        int randomNumber = std::rand() % (sum);
        //cout<<"Random number: "<<randomNumber<<endl;
        for(int i = 0; i < sums.size(); i++){
            if(sums[i] > randomNumber){
                //cout<<"index "<<i<<" with value "<<sums[i]<<" is greater or equal to "<<randomNumber<<endl;
                if(i == 0){
                    total0++;
                } else if(i == 1){
                    total1++;
                } else if (i == 2){
                    total2++;
                } else if (i == 3){
                    total3++;
                }
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