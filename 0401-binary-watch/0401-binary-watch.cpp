class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int hour = 0; hour <= 11; hour++) {
            for(int minute = 0; minute <= 59; minute++){
                int hourDigits = __builtin_popcount(hour);
                int minuteDigits = __builtin_popcount(minute);
                int totalDigits = hourDigits + minuteDigits;
                if(totalDigits == turnedOn) {
                    string hourString = to_string(hour);
                    string minuteStringNoPad = to_string(minute);
                    string minuteString;
                    if(minuteStringNoPad.size() < 2) {
                        minuteString = "0" + minuteStringNoPad;
                    } else {
                        minuteString = minuteStringNoPad;
                    }
                    res.push_back(hourString + ":" + minuteString);
                }
            }
        }
        return res;
    }
};