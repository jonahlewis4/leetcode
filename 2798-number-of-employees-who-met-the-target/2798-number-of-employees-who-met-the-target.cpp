class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int met = 0;
        for(const int hour : hours) {
            if(hour >= target) {
                met++;
            }
        }
        return met;
    }
};