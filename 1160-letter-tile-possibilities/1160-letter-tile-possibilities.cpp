class Solution {
private:
int possibilities = 0;
unordered_set<string> set;
string cur = "";
string tiles;
unordered_map<char, int> maxCount;
unordered_map<char, int> curCount;
public:
    int numTilePossibilities(string tiles) {
        this->tiles = tiles;
        for(char c : tiles){
            maxCount[c]++;
        }
        dfs();
        return possibilities - 1;
    }
    void dfs() {
        if(set.find(cur) != set.end()){
            return;
        }
        if(!cur.empty() && (curCount[cur.back()] > maxCount[cur.back()])){
            return;
        }
        set.insert(cur);
        possibilities++;
        if(cur.size() == tiles.size()){
            return;
        }

        for(char c : tiles){
            cur.push_back(c);
            curCount[c]++;
            dfs();
            curCount[c]--;
            cur.pop_back();
        }
    }


};