class Solution {
    double calc(const string& dividend, const string& divisor, unordered_map<string, unordered_map<string, double>>& chart, unordered_set<string>& visited){
        
        if(visited.contains(dividend)) {
            return -1;
        }

        if(chart.contains(dividend) && chart[dividend].contains(divisor)) {
            return chart[dividend][divisor];
        }

        visited.insert(dividend);
        double quotient = -1;
        for(const auto& [subDividend, subQuotient] : chart[dividend]) {
            double subProblem = calc(subDividend, divisor, chart, visited);
            if(subProblem != -1) {
                quotient = subProblem * subQuotient;
                break;
            }
        }
        visited.erase(dividend);
        if(quotient != -1) {
            chart[dividend][divisor] = quotient;
            chart[divisor][dividend] = 1/quotient;
        } 
        return quotient;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> chart;

        for(int i = 0; i < equations.size(); i++) {
            const vector<string>& eq = equations[i];
            const string& dividend = eq.front();
            const string& divisor = eq.back();
            chart[dividend][divisor] = values[i];
            chart[divisor][dividend] = 1/values[i];
            chart[dividend][dividend] = 1.0;
            chart[divisor][divisor] = 1.0;
        }

        vector<double> resArray(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            const vector<string>& q = queries[i];
            const string& dividend = q.front();
            const string& divisor = q.back();
            unordered_set<string> visited;
            double res = calc(dividend, divisor, chart, visited);
            resArray[i] = res;
        }
        return resArray;
    }
};