class Solution {
    class Date{
    private:
        int _year;
        int _month;
        int _day;
    
        static constexpr array<int, 12> dayCounts = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    int daysSince1970() const {
        int years = _year - 1970;
        int months = _month;
        int days = _day;

        //find out how many days are in those years.
        int numLeapYears = (years + 1) / 4;
        int yearDays = 365 * years + numLeapYears;

        //fnd out how many days are in those months. 
        int monthDays = 0;
        for(int i = 0; i < months - 1; i++) {
            monthDays += dayCounts[i];
        }
        if(_year % 4 == 0 && months >= 3){
            monthDays++;
        }
        if(_year == 2100 && months >= 3) {
            monthDays--;
        }

        return yearDays + monthDays + days - 1;
    }

    public:
        Date(const string& date){
            _year = stoi(date.substr(0,4));
            _month = stoi(date.substr(5,2));
            _day = stoi(date.substr(8,2));
        }
        
        int operator-(const Date& other) const {
            int thisNum = daysSince1970();
            int otherNum = other.daysSince1970();

            cout<<thisNum<<endl;
            cout<<otherNum<<endl;

            return thisNum - otherNum;
        }
        
    };
public:
    int daysBetweenDates(string date1, string date2) {
        Date d1 = Date(date1);
        Date d2 = Date(date2);

        return abs(d1 - d2);
    }
};