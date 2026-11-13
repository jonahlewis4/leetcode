/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> id2Emp;
        for(Employee* employee: employees) {
            id2Emp[employee->id] = employee;
        }

        int importance = 0;
        queue<Employee*> q;
        q.push(id2Emp[id]);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                Employee* e = q.front();
                q.pop();
                importance += e->importance;
                for(const int c : e->subordinates){
                    q.push(id2Emp[c]);
                }
            }
        }

        return importance;
    }
};