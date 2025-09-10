class Solution {
    static vector<unordered_set<int>> setify(const vector<vector<int>>& languages) {
        vector<unordered_set<int>> res(languages.size());
        for(int i = 0; i < languages.size(); i++) {
            const vector<int>& userLanguages = languages[i];
            for(const int language : userLanguages) {
                res[i].insert(language);
            }
        }
        return res;
    }

    static void updateForFriend(vector<unordered_set<int>>& langCopy,
        int language,
        int friend1,
        unordered_set<int>& usersNeedingChange
    ){
        if(langCopy[friend1].find(language) == langCopy[friend1].end()){
            usersNeedingChange.insert(friend1);
        }
    }

    static bool friendsDoNotShareLanguage(vector<unordered_set<int>>& langCopy, int friend1, int friend2) {
        for(const int lang : langCopy[friend1]){
            if(langCopy[friend2].find(lang) != langCopy[friend2].end()) {
                return false;
            }
        }
        return true;
    }
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<unordered_set<int>> languagesByUser = setify(languages); 
        int minChanges = languages.size();

        vector<vector<int>> edgesWithoutCommon;
        for(const vector<int>& friendship : friendships) {
            int friendship1 = friendship[0] - 1;
            int friendship2 = friendship[1] - 1;

            if(friendsDoNotShareLanguage(languagesByUser, friendship1, friendship2)) {
                edgesWithoutCommon.push_back({friendship1, friendship2});
            }
        }

        for(int language = 1; language <= n; language++) {
            int changes = 0;
            unordered_set<int> usersNeedingChange;
            for(const vector<int>& edge : edgesWithoutCommon) {
                int friend1 = edge[0];
                int friend2 = edge[1];

                updateForFriend(languagesByUser, language, friend1, usersNeedingChange);
                updateForFriend(languagesByUser, language, friend2, usersNeedingChange);
            }
            changes = usersNeedingChange.size();
            minChanges = min(minChanges, changes);
        }
        return minChanges;
    }
};