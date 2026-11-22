class Solution {
    class Parser{
        const vector<string>& lines;
        int lineI = 0;
        int line = 0;
        vector<string> res;
        string curLine;

        bool atEnd(){
            return line >= lines.size();
        }

        bool AtComment() {
            return lineComment() || blockComment();
        }

        void updateLine() {
            const string& tempLine = lines[line];
            curLine += tempLine[lineI];
            lineI++;
        }

        bool endOfLine() {
            const string& tempLine = lines[line];
            if(lineI >= tempLine.size()) {
                return true;
            }
            return false;
        }

        void resetLine() {
            if(curLine.size() == 0) {
                lineI = 0;
                line++;
                return;
            }
            res.push_back(curLine);
            curLine.clear();
            lineI = 0;
            line++;
        }

        void resetLineWithJoin() {
            lineI = 0;
            line++;
        }

        void goToComment() {
            while(!atEnd() && !AtComment()){
                if(endOfLine()){
                    resetLine();
                } else {
                    updateLine();
                }
            }
        }

        bool blockComment() {
            const string& tempLine = lines[line];

            if(lineI + 1 >= tempLine.size()) {
                return false;
            }

            return tempLine[lineI] == '/' && tempLine[lineI + 1] == '*';
        }

        bool lineComment() {
            const string& tempLine = lines[line];

            if(lineI + 1 >= tempLine.size()) {
                return false;
            }
            return tempLine[lineI] == '/' && tempLine[lineI + 1] == '/';
        }

        void parseLineComment() {
            resetLine();
        }

        bool atBlockEnd() {
            const string& tempLine = lines[line];

            if(lineI + 1 >= tempLine.size()) {
                return false;
            }
            return tempLine[lineI] == '*' && tempLine[lineI + 1] == '/';
        }

        void updateLineSkip() {
            lineI++;
        }

        void parseBlockComment() {
            lineI += 2;
            while(!atBlockEnd()) {
                updateLineSkip();
                if(endOfLine()) {
                    resetLineWithJoin();
                }
            }
            lineI += 2;
        }
    public:
        Parser(const vector<string>& lines) : lines(lines){}
        vector<string> parse(){
            while(!atEnd()) {
                goToComment();
                
                //need this here in case we never reach a comment.
                if(atEnd()){
                    break;
                }
                if(lineComment()){
                    parseLineComment();
                } else {
                    parseBlockComment();
                }
            }
            return res;
        }
    };
public:
    vector<string> removeComments(vector<string>& source) {
        Parser p(source);
        return p.parse();
    }
};