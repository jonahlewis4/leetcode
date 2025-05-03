class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> lines;
        int curLineLength = 0;
        vector<string> curLine = {};
        vector<string> res;
        for(const auto & word : words){
            //add the current word to the line if it fits.
            
            int curWordLength = word.size();
            if(curLine.size() == 0){
                curLineLength += curWordLength;
                curLine.push_back(word);
            } else {
                string wordWithSpace = " " + word;
                //if we can fit the current word with a space in add it
                if(curLineLength + wordWithSpace.size() <= maxWidth){
                    curLineLength += wordWithSpace.size();
                    curLine.push_back(wordWithSpace);
                } else /* if we can't fit the word in we need to start a new one */ {
                    
                    //save the current word line
                    if(curLine.size() == 1){
                        saveLeft(curLine, res, maxWidth);
                    } else {
                        save(curLineLength, maxWidth, curLine, res);
                    }

                    //start a new line
                    curLineLength = 0;
                    curLine = {};
                    auto &nextLine = curLine;
                    curLineLength += curWordLength;
                    nextLine.push_back(word);
                }
            }
        }
        
        //save final line
        saveLeft(curLine, res, maxWidth);
        return res;
    }
    inline void saveLeft(const vector<string> &line, vector<string> &res, int maxWidth) const {
        string finalString = "";
        for(const auto & s : line){
            finalString += s;
        }
        while(finalString.size() < maxWidth){
            finalString.push_back(' ');
        }
        res.push_back(finalString);
    }
    inline void save(int curLineLength, int maxWidth, vector<string> &line, vector<string> &res) const {
        //determine the number of spaces we need to add. 
        //the answer to this will be the curLineLength minus the maxWidth

        int remainingSpaces = maxWidth - curLineLength;

        //add spaces to the end of words except the final word until we are out of reminaingSpaces;
        while(remainingSpaces > 0){
            for(int i = 0; i < line.size() - 1; i++){
                if(remainingSpaces <= 0){
                    break;
                }
                line[i].push_back(' ');
                remainingSpaces--;
            }        
        }

        //join all the lines together;
        string joined = "";
        for(const auto & s : line){
            joined += s;
        }
        res.push_back(joined);
    }
};