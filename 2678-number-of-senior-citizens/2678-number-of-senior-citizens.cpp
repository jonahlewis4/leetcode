class Solution {
public:
    int countSeniors(vector<string>& details) {
        int over60 = 0;
        for(const string& detail : details) {
            //0-9 is phone
            //10 is gender
            //11-12 is age
            int age = 0;
            age += detail[11] - '0';
            age *= 10;
            age += detail[12] - '0';

            if(age > 60) {
                over60++;
            }
        }
        return over60;
    }
};