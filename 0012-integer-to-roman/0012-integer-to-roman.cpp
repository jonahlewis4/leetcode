class Solution {
private: 
vector<pair<char, int>> numerals = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};
unordered_map<char, pair<string, int>> preceeding = {
    {'V', {"IV", 4}},
    {'X', {"IX", 9}},
    
    {'L', {"XL", 40}},
    {'C', {"XC", 90}},

    {'D', {"CD", 400}},
    {'M', {"CM", 900}},
};
public:
    string intToRoman(int num) {
        string roman = "";
        
        
        while(num > 0){
            int firstDig = firstDigit(num);
            //if the symbol does not start with 4 or 9
            //select the largest possible value we can, substract it and convert remainder to numeral.
            if(firstDig != 4 && firstDig != 9){
                auto [numeral, value] = largestLessThan(num);

                num -= value;
                roman += numeral;
            } else {
                auto [largerNumeral, largerValue] = firstGreaterThan(num);
                
                auto [numerals, value] = preceeding[largerNumeral];
                roman += numerals;
                num -= value;
            }
        }

        return roman;
    }
    pair<char, int> largestLessThan(const int num){
        for(auto itr = numerals.rbegin(); itr != numerals.rend(); ++itr){
            const char numeral = itr->first;
            const int value = itr->second;

            if(value > num){
                continue;
            }

            return *itr;
        }

        return {};

    }
    pair<char, int> firstGreaterThan(const int num){
        for(auto itr = numerals.begin(); itr != numerals.end(); ++itr){
            const char numeral = itr->first;
            const int value = itr->second;

            if(value < num){
                continue;
            }
            return *itr;
        }
        return {};
    }
    int firstDigit(int num){
        while(num > 9){
            num /= 10;
        }
        return num;
    }

};