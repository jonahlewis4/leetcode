class Solution {
public:
   int minimumDeletions(string word, int k) {
    vector<int> freq(26, 0);
    int deleted = 0, ans = word.size();
    for(auto c: word) freq[c-'a']++;             
    sort(freq.begin(), freq.end());              
    for(int i = 0; i < freq.size(); ++i){        
        int res = deleted, minFreq = freq[i];    
        for(int j = i + 1; j < freq.size(); j++){  
            if(freq[j] - minFreq <= k) continue;    
            res += freq[j] - minFreq - k;        
        }
        ans = min(ans, res);                     
        deleted += freq[i];                      
    }
    return ans;
}
};