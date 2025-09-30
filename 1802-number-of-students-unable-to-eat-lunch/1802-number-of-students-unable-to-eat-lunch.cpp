class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zEnjoyers = 0;
        int oEnjoyers = 0;
        for(const int i : students) {
            if(i == 0) {
                zEnjoyers++;
            } else {
                oEnjoyers++;
            }
        }

        for(int i = 0; i < sandwiches.size(); i++) {
            if(sandwiches[i] == 0 && zEnjoyers == 0) {
                return oEnjoyers;
            }
            if(sandwiches[i] == 1 && oEnjoyers == 0) {
                return zEnjoyers;
            }

            if(sandwiches[i] == 0) {
                zEnjoyers--;
            }
            if(sandwiches[i] == 1) {
                oEnjoyers--;
            }
        }

        return zEnjoyers + oEnjoyers;
    }
};