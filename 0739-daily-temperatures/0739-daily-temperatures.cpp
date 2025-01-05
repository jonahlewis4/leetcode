class Solution {
private:
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        int largest = temperatures[temperatures.size() - 1];

        for(int i = temperatures.size() - 2; i >= 0; i--){
            if(temperatures[i] >= largest){
                largest = temperatures[i];
                res[i] = 0;
            } else {
                int j = i + 1;
                while(temperatures[j] <= temperatures[i]){
                    j += res[j];
                }
                res[i] = j - i;
            }
        }
        return res;


    }
};