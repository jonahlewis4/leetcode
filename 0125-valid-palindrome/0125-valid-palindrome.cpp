class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r){
            int lc = s[l];
            int rc = s[r];
            while(!isalnum(lc) && l < r){
                l++;
                lc = s[l];
            }
            while(!isalnum(rc) && r > l){
                r--;
                rc = s[r];
            }

            lc = tolower(lc);
            rc = tolower(rc);
            if(lc != rc){
                return false;
            }


            l++;
            r--;
        }
        return true;
    }
};