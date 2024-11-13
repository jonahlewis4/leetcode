
//video: https://www.youtube.com/watch?v=Ua0GhsJSlWM
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //if chars are equal set to bottom right + 1
        //if not equal set to max of right and left + 1

        int rows = text1.size(); 
        int cols = text2.size();

        int arr[rows + 1][cols + 1];
        //set bottom row and right column to 0

        for(int i = 0; i < cols + 1; i++){
            arr[rows][i] = 0; 
        }
        for(int i = 0; i < rows + 1; i++){
            arr[i][cols] = 0;
        }

        for(int i = rows - 1; i >= 0; i--){
            for(int j = cols - 1; j >= 0; j--){
                //note: j is iterating through text2
                //      i is iterating through text1

                
                if(text1[i] == text2[j]){
                    arr[i][j] = 1 + arr[i + 1][j + 1];
                } else {
                    arr[i][j] = max(arr[i][j + 1], arr[i + 1][j]);
                }
            }

        }
        return arr[0][0];
    }
};