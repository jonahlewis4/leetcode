class Solution {
    static vector<string> split(const string & s, char delim){
        vector<string> res;

        string cur = "";
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == delim){
                res.push_back(cur);
                cur = "";
            } else {
                cur += c;
            }
        }
        res.push_back(cur);
        return res;
    }

    struct Transaction {
        string name;
        int time;
        int amount;
        string city;
        bool valid = true;

        Transaction(const string &data) {
            auto splitten = split(data, ',');
            name = splitten[0];
            time = stoi(splitten[1]);
            amount = stoi(splitten[2]);
            city = splitten[3];
        }
        Transaction(){}

        void Validate(vector<Transaction> &transactions){
            if(!valid){
                return;
            }
            
            if(amount > 1000){
                valid = false;
                return;
            }


            for(auto & otherTransaction : transactions){
                if(abs(otherTransaction.time - time) <= 60 && otherTransaction.city != city){
                    valid = false;
                    otherTransaction.valid = false;
                }
            }

        }

        string ToString() const {
            return name + "," + to_string(time) + "," + to_string(amount) + "," + city;
        }
    };

public:
    vector<string> invalidTransactions(const vector<string>& _transactions) {
        //a more efficient solution is to map first the time, then name, then cities, and loop from -60 to 60 on the time and see for all names if at any given time someone purchased in a different city
        
        
        vector<Transaction> transactions(_transactions.size());
        for(int i = 0; i < _transactions.size(); i++){
            transactions[i] = Transaction(_transactions[i]);
        }

        unordered_map<string, vector<Transaction>> map;
        for(const auto & transaction : transactions){
            map[transaction.name].push_back(transaction);
        }


        for(auto & vecPair : map){
            for(auto & transaction : vecPair.second){
                transaction.Validate(vecPair.second);
            }
            
        }

        vector<string> res;
        for(auto & vecPair : map){
            for(auto & transaction : vecPair.second){
                if(!transaction.valid){
                    res.push_back(transaction.ToString());
                }
            }
            
        }
        return res;

    }


    
};