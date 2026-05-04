class Solution {
private:
public:
    string reformatDate(string date) {
        static const unordered_map<string, string> monthMap = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
            {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
            {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
        };

        int day;
        if(!isdigit(date[1])) {
            day = date[0] - '0';
        } else {
            day = date[0] - '0';
            day *= 10;
            day += date[1] - '0';
        }

        int spaceIndex = date.find(' ');
        string monthStr = date.substr(spaceIndex + 1, 3);
        const string monthRes = monthMap.at(monthStr);

        int spaceIndex2 = date.find(' ', spaceIndex + 1);
        string yearString = date.substr(spaceIndex2 + 1, 4);

        return yearString + "-" + monthRes + "-" +
            (day < 10 ? ("0" + to_string(day)) : to_string(day)); 
    }
};