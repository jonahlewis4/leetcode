class Solution {
public:
    int candy(vector<int>& ratings) {
        int up = 0;
        int down = 0;
        int lastUp = 0;

        int total = 1;
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1]){
                up++;
                down = 0;
                lastUp = up + 1;
                total += up + 1;
            } else if (ratings[i] < ratings[i - 1]){
                down++;
                up = 0;
                if(down >= lastUp) {
                    total++;
                }
                total += down;
            } else {
                up = 0;
                down = 0;
                lastUp = 0;
                total++;
            }
        } 
        return total;
    }
};