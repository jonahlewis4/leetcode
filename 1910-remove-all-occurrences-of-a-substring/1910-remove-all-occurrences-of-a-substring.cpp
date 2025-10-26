class Solution {
    // void removeSubstr(string& s, int ptsPerRemoval, string search){
    //     int l = 0;
    //     for(int r = 0; r < s.size(); r++) {
    //         s[l] = s[r];
    //         l++;
            
    //         if(l >= 2 && s[l - 2] == search[0] && s[l - 1] == search[1]){
    //             l = l - 2;
    //             total += ptsPerRemoval;
    //         }
    //     }

    //     for(int i = s.size() - 1; i >= l; i--) {
    //         s.pop_back();
    //     }
    // }
public:
    string removeOccurrences(string s, string part) {
        int l = 0;
        for(int r = 0; r < s.size(); r++) {
            s[l] = s[r];
            l++;

            if(l >= part.size()){
                bool skip = false;
                for(int i = l - part.size(); i < l; i++){
                    if(s[i] != part[i - (l - part.size())]){
                        skip = true;
                        break;
                    }
                }
                
                if(skip){
                    continue;
                }
                l -= part.size();
            }
        }

        for(int i = s.size() - 1; i >= l; i--) {
            s.pop_back();
        }

        return s;
    }
};