class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        std::unordered_set<string> divs;
        for(int i = 0; i < str2.size(); i++){
            int k = 0;
            bool match = true;
            for(int j = 0; j < str2.size(); j++){
                if(str2[j] != str2[k]){
                    match = false;
                    break;
                }
                k++;
                k = k % (i + 1);
            }
            if(match && k == 0){
                divs.insert(str2.substr(0, i + 1));
            }
        }
        
        string longest = "";
        for(const auto & divisor : divs){
            if(divides(str1, divisor) && divisor.size() > longest.size()){
                longest = divisor;
            }
        }
        return longest;
    }

    bool divides(const string &s, const string& possibleDivisor){
        int divisorIndex = 0;
        int sIndex = 0;
        while(sIndex < s.size()){
            if(s[sIndex] != possibleDivisor[divisorIndex]){
                return false;
            }
            sIndex++;
            divisorIndex++;
            divisorIndex = divisorIndex % possibleDivisor.size();
        }
        return divisorIndex == 0;
    }
};