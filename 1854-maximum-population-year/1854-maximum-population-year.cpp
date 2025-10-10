class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> years(101);
        for(const auto & log : logs) {
            int birth = log.front() - 1950;
            int death = log.back() - 1950;
            
            years[birth]++;
            years[death]--;
        }

        int highest = 0;
        int sum = 0;
        int bestYear = 0;
        for(int i = 0; i < years.size(); i++){
            int v = years[i];
            sum += v;
            if(sum > highest) {
                highest = sum;
                bestYear = i;
            }
        }
        return bestYear + 1950;
    }
};