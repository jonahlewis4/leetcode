class Solution {
private:
public:
    int minMovesToMakePalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        int swaps = 0;
        while(l < r){
            if(s[l] != s[r]){
                int k = l + 1;
                while(k < r){
                    if(s[k] == s[r]){
                        break;
                    }
                    k++;
                }
                if(k == r){
                    swaps += r - s.size() / 2;
                    r--;
                    continue;
                }
                while(k >= l + 1){
                    swap(s[k], s[k - 1]);
                    swaps++;
                    k--;
                } 
                
            }
            l++;
            r--;
        }
        
        return swaps;
    }
    

    
};