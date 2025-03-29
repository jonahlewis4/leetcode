class Solution {
private:
int possibilities = 0;
unordered_set<string> set;
string cur = "";
string tiles;
vector<bool> used;

public:
    int numTilePossibilities(const string &tiles) {
        this->tiles = tiles;
        used.resize(tiles.size(), false);
        dfs();
        return possibilities - 1;
    }   
    void dfs() {
        if(set.find(cur) != set.end()){
            return;
        }
       
       
        set.insert(cur);
        possibilities++;
        if(cur.size() == tiles.size()){
            return;
        }

        for(int i = 0; i < tiles.size(); i++){
            if(used[i]){
                continue;
            }
            char c = tiles[i];
            cur.push_back(c);
            used[i] = true;
            dfs();
            used[i] = false;
            cur.pop_back();
        }
    }


};