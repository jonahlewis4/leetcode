class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int matches = 0;
        for(const vector<string>& item : items) {
            const string& type = item[0];
            const string& color = item[1];
            const string& name = item[2];

            if( ruleKey == "type" && ruleValue == type ||
            ruleKey == "color" && ruleValue == color ||
            ruleKey == "name" && ruleValue == name ) {
                matches++;
            }
        }
        return matches;
    }
};