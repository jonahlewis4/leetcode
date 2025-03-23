class Solution {
private:
    struct Point{
        bool pacific = false;
        bool atlantic = false;
        int height = 0;
        Point(){}
        Point(const int _height){
            height = _height;
        }

        bool isReachable() const {
            return pacific && atlantic;
        }

    };
    vector<vector<Point>> points;

    vector<vector<int>> calcReachable() const {
        vector<vector<int>> res;
        for(int r = 0; r < points.size(); r++){
            for(int c = 0; c < points[r].size(); c++){
                if(points[r][c].isReachable()){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }

    void initPoints(const vector<vector<int>> & heights){
        for(int r = 0; r < heights.size(); r++){
            for(int c = 0; c < heights[r].size(); c++){
                points[r][c] = Point(heights[r][c]);
            }
        }
    }
    void printPacific() {
        for(int r = 0; r < points.size(); r++){
            for(int c = 0; c < points[r].size(); c++){
                if(points[r][c].pacific){
                    cout<<points[r][c].height;
                } else {
                    cout<<" ";
                }
                cout<<" ";
            }
            cout<<endl;
        }
    }
    void calcPacific() {
        for(int r = 0; r < points.size(); r++){
            dfsPacific(r, 0, 0);
        }
        for(int c = 0; c < points[0].size(); c++){
            dfsPacific(0, c, 0);
        }
    }
    void dfsPacific(int r, int c, int previous){
       
        if(r < 0 || c < 0 || r >= points.size() || c >= points[r].size()){
            return;
        }
        if(points[r][c].pacific == true){
            return;
        }
        if(points[r][c].height >= previous){
            points[r][c].pacific = true;
        } else {
            return;
        }
        dfsPacific(r + 1, c, points[r][c].height);
        dfsPacific(r, c + 1, points[r][c].height);
        dfsPacific(r - 1, c, points[r][c].height);
        dfsPacific(r, c - 1, points[r][c].height);
    }
    void calcAtlantic() {
        for(int r = 0; r < points.size(); r++){
            dfsAtlantic(r, points[r].size() - 1, 0);
        }
        for(int c = 0; c < points[0].size(); c++){
            dfsAtlantic(points.size() - 1, c, 0);
        }
    }
    void dfsAtlantic(int r, int c, int previous){
        if(r < 0 || c < 0 || r >= points.size() || c >= points[r].size()){
            return;
        }
        if(points[r][c].atlantic == true){
            return;
        }
        if(points[r][c].height >= previous){
            points[r][c].atlantic = true;
        } else {
            return;
        }
        dfsAtlantic(r - 1, c, points[r][c].height);
        dfsAtlantic(r, c - 1, points[r][c].height);
        dfsAtlantic(r + 1, c, points[r][c].height);
        dfsAtlantic(r, c + 1, points[r][c].height);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        points = vector<vector<Point>>(heights.size(), vector<Point>(heights[0].size()));
        initPoints(heights);
        calcPacific();
        //printPacific();
        calcAtlantic();
        return calcReachable();
    }



    
};