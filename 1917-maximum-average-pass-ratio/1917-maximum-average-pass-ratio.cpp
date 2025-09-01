class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        class Class {
            int n;
            int passes;
        private:
            double NextAverageDelta() const {
                double nextAverage = ((double) passes + 1) / (n + 1);
                return nextAverage - Average();
            }
        public:
            double nextAverageDelta;
            Class(const vector<int>& passFail) {
                passes = passFail[0];
                n = passFail[1];
                nextAverageDelta = NextAverageDelta();
            }
            void AddStudent() {
                n++;
                passes++;
                nextAverageDelta = NextAverageDelta();
            }
            double Average() const {
                return (double) passes / n;
            }
        };


        priority_queue<Class, vector<Class>, decltype([](const Class& a, const Class& b){
            return a.nextAverageDelta < b.nextAverageDelta;
        })> pq;

        for(int i = 0; i < classes.size(); i++) {
            pq.push(Class(classes[i]));
            
        }

        for(int i = 0; i < extraStudents; i++) {
            Class c = pq.top();
            pq.pop();
            c.AddStudent();
            pq.push(c);
        }

        double sum = 0;
        while(!pq.empty()) {
            Class c = pq.top();
            pq.pop();
            sum += c.Average();
        }
        return sum / classes.size();
    }
};