class Solution {
public:
    bool checkRecord(string s) {
        int lateStreak = 0;
        int absentCount = 0;

        for(const char c : s) {
            switch (c) {
                case 'A':
                    absentCount++;
                    if(absentCount >= 2) {
                        return false;
                    }
                    lateStreak = 0;
                    break;
                case 'L':
                    lateStreak++;
                    if(lateStreak >= 3) {
                        return false;
                    }
                    break;
                case 'P':
                    lateStreak = 0;
                    break;
            }
        }
        return true;
    }
};