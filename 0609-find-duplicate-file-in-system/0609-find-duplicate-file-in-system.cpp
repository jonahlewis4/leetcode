class Solution {
    class Directory;
    class File{
    public:
        string name;
        string content;
        string directory;
        File(const string& name, const string& content, Directory& directory): name(name), content(content), directory(directory.name){}
        friend string to_string(const File& f) {
            return f.directory + "/" + f.name;
        }
        friend ostream& operator<<(ostream& out, const File& f) {
            return out<<to_string(f);
        }
    };
    class Directory {
    public:
        string name;
        vector<File> files;
        Directory(const string& path) {
            int firstSpace = path.find(' ');
            name = path.substr(0, firstSpace);

            int lastSpace = firstSpace;
            int nextOpenParen = -1;
            while((nextOpenParen = path.find('(', nextOpenParen + 1)) != string::npos){
                int nameStart = lastSpace + 1;
                string fileName = path.substr(nameStart, nextOpenParen - nameStart);
                int contentStart = nextOpenParen + 1;
                int nextCloseParen = path.find(')', contentStart);
                string content = path.substr(contentStart, nextCloseParen - contentStart);
                lastSpace = nextCloseParen+1;
                File f(fileName, content, *this);
                files.push_back(f);
            }
        }
        friend string to_string(const Directory& d) {
            return d.name;
        }
        friend ostream& operator<<(ostream& out, const Directory& d) {
            return out<<to_string(d);
        }
    };
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<File>> filesByContent;
        for(const string& path : paths) {
            Directory d(path);
            for(const File& file : d.files){
                filesByContent[file.content].push_back(file);
            }
        }
        vector<vector<string>> res;
        for(const pair<string, vector<File>>& p : filesByContent){
            const vector<File>& files = p.second;
            if(files.size() == 1) {
                continue;
            }
            vector<string> subRes;
            subRes.reserve(files.size());
            for(const File& file : files) {
                subRes.push_back(to_string(file));
            }
            res.push_back(subRes);
        }

        return res;
    }
};