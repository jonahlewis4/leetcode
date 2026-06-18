class Solution {
public:
    double angleClock(int hour, int minutes) {
        int oneHour = 360/12;
        double progression =  (double)minutes/60;
        double hourBonus = progression * oneHour;
        int hourBase = hour%12 * oneHour;
        double hourTotal = hourBonus + hourBase;
        int oneMinute = 360/60;
        int minuteBase = minutes * oneMinute;
        
        double diff = abs(minuteBase - hourTotal);
        return min(diff, 360-diff);
    }
};