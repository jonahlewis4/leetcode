class Solution {
public:
    vector<int> partitionLabels(string s) {
        //get last of each char

        //for every char
            //if i > partition end 
                //new partition

            //get last
            //if last > partition end
                //expand partition to last
            
        unordered_map<char, int> last;
        for(int i = 0; i < s.size(); i++) {
            last[s[i]] = i;
        }

        vector<int> res;
        int partitionBegin = 0;
        int partitionEnd = last[s[0]];

        for(int i = 1; i < s.size(); i++) {
            char c = s[i];
            if(i > partitionEnd) {
                res.push_back(partitionEnd - partitionBegin + 1);
                partitionBegin = i;
            }

            partitionEnd = max(partitionEnd, last[c]);
        }


        res.push_back(partitionEnd - partitionBegin + 1);

        return res;
    }
};