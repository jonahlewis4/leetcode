class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sumApples = 0;
        for(const int a : apple) {
            sumApples += a;
        }

        sort(capacity.begin(), capacity.end());
        
        int boxesUsed = 0;
        for(int i = capacity.size() - 1; i >= 0; i--) {
            boxesUsed++;
            sumApples -= capacity[i];
            if(sumApples <= 0) {
                return boxesUsed;
            }
        }

        return -1;
    }
};