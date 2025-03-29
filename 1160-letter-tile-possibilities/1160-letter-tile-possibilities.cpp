class Solution {
private:
int possibilities = 0;
unordered_map<char, int> avail;
public:
    int numTilePossibilities(const string &tiles) {
        for(char c : tiles){
            avail[c]++;
        }
        dfs();
        return possibilities;
    }   
    void dfs() {
        for(auto & tup : avail){
            auto & [key, count] = tup;
            if(count == 0){
                continue;
            }
            possibilities++;
            count--;
            dfs();
            count++;
        }
    }


};