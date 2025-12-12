class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), []
            (const vector<string>& e1, const vector<string>& e2){
                int stamp1 = stoi(e1[1]);
                int stamp2 = stoi(e2[1]);
                const string& type1 = e1[0];

                if(stamp1 < stamp2) {
                    return true;
                } else if (stamp1 > stamp2) {
                    return false;
                } else if (type1 == "OFFLINE") {
                    return true;
                } else {
                    return false;
                }
            }
        );
        
        vector<int> res(numberOfUsers, 0);

        vector<bool> online(numberOfUsers, true);
        queue<pair<int, int>> arrivals;

        for(const vector<string>& event : events) {
            
            
            const string& type = event[0];
            const int timestamp = stoi(event[1]);
            const string& data = event[2];

            while(!arrivals.empty() && arrivals.front().first <= timestamp){
               
                online[arrivals.front().second] = true;
                

                arrivals.pop();
            }


            if(type == "MESSAGE") {
                //parse message 

                if(data == "ALL"){
                    for(int& i : res){
                        i++;
                    }
                } else if (data == "HERE") {
                    for(int i = 0; i < res.size(); i++) {
                        if(online[i]){
                            res[i]++;
                        }
                    }
                } else {
                    int curId = -1;
                    for(const char c : data) {
                        if(c == 'i'){
                            if(curId != -1) {
                                res[curId]++;
                                curId = 0;
                            }
                        } else if (isdigit(c)){
                            if(curId == -1) {
                                curId = 0;
                            }
                            curId *= 10;
                            curId += c - '0';
                        }
                    }

                    if(curId != -1) {
                        res[curId]++;
                        curId = 0;
                    }
                }

            } else {
                //parse offline 
                int nextOnline = timestamp + 60;
                int id = 0;
                for(int i = 0; i < data.size(); i++) {
                    id *= 10;
                    id += data[i] - '0';
                }
                arrivals.push({nextOnline, id});
                online[id] = false;
            }
        }

        return res;
    }
};