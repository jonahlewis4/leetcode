class Solution {
    vector<string> labels {
        "Billion",
        "Million",
        "Thousand",
        ""
    };
    vector<string> intToString{
        "",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine"
    };
    vector<string> intToTeen{
        "Ten",
        "Eleven",
        "Twelve",
        "Thirteen",
        "Fourteen",
        "Fifteen",
        "Sixteen",
        "Seventeen",
        "Eighteen",
        "Nineteen"
    };
    vector<string> intToTen{
        "",
        "",
        "Twenty",
        "Thirty",
        "Forty",
        "Fifty",
        "Sixty",
        "Seventy",
        "Eighty",
        "Ninety"
    };
public:
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        string res = "";
        string word = to_string(num);
        
        //read from left to right

        
    
        
        int last3 = 0;

        for(int i = 0; i < word.size(); i++){

            const auto isTensPlace = [i, &word, this]() {
                //starting place is determined by size % 3.
                //if length is 0, starting place is hundreds
                //if length is 1, starting place is ones,
                //if length is 2, starting place is tens,
                //if length is 3, starting place is hundreds.

                //so, remaining length % 3 == 2, we are in the tens place.
                // if parsing 23 and i = 0, size is 2, i = 0, 2 - 0 = 2, tens place. 
                // (word.size() - i) % 3 indicates if we are in the tens place.
                return ((word.size() - i) % 3) == 2;
            };
            const auto isOnesPlace = [i, &word, this](){
                //same logic as above but check if mod is 1
                return ((word.size() - i) % 3) == 1;
            };
            const auto isHundredsPlace = [i, &word, this]{
                return ((word.size() - i) % 3) == 0;
            };

            const auto labelIndex = [i, &word, this](){
                //if string is 10 long start at billion
                //if string is 7 long start at million
                //if string is 4 long start at thousand.
                //if string is 1 long start at "". 

                //billion is index 0
                //million is index 1 
                //thousand is index 2
                //"" is index 3

                //10 / 3 = 3;
                //7 / 3 = 2;
                //4 / 3 = 1;
                //1 / 3 = 0;

                //4 - length / 3 - 1

                //if ten long and on the 0, 1, 2 index, should be billion)
                //when we reach 3 index (10 - 3 == 7) then we are in the millions place.
                int labelIdx = labels.size() - (word.size()-i) / 3 - 1;
                return labelIdx;
            };
            
            const auto addLabel = [i, &word, this, &res, &labelIndex]() {
                string newLabel = labels[labelIndex()];
                if(newLabel != ""){
                    res += labels[labelIndex()];
                    res += " ";
                }
            };

            //adjust last3 to be the value of the last 3 digits. 
            //123456.
            //123
            //234
            // 23 = 123 % 100
            // n % 100 * 10 + new digit.

            last3 = last3 % 100 * 10 + word[i] - '0';


            //if Hundred's place, print Hundred
            if(isHundredsPlace()){
                if(word[i] != '0'){
                    res += intToString[word[i] - '0'];
                    res += " Hundred ";
                }
            }
            //if in tens's place, check if 1. 
            else if(isTensPlace()){
                //if so, map to teen and skip next one
                //else proceed normally.
                if(word[i] == '1'){
                    i++; //skip this next ones place.
                    res += intToTeen[word[i] - '0'];
                    res += " ";

                    addLabel();
                } else if (word[i] != '0'){
                    res += intToTen[word[i] - '0'];
                    res += " ";
                }
            } else if(isOnesPlace()) {
                if(word[i] != '0'){
                    //add digit as string.
                    res += intToString[word[i] - '0'];
                    res += " ";
                }
                //add label if last 3 weren't all 0.
                if(last3 != 0){
                    addLabel();
                }  
                  
            }
        }
       
        res.pop_back();
        return res;
    }
};