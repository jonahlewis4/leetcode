class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> smallCount;

        for(const char c : s1){
            smallCount[c]++;
        }

        int l = 0;
        int r = 0;


        std::unordered_map<char, int> bigCount;
        while(r < s2.size()){
            bigCount[s2[r]]++;
            
            while(bigCount[s2[r]] > smallCount[s2[r]]){
                bigCount[s2[l]]--;
                l++;
            }    
            if(r - l + 1 == s1.size()){
                return true;
            }
            r++;


        }
        return false;
       
    }
};