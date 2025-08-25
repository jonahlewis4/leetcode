class Solution {
    template <typename T>
    class SpiralTraverser{
        const vector<vector<T>>& _mat;
        int _i = 0;
        int _r = 0;
        int _c = 0;
        int _totalElements;
        bool atEnd() const {
            return _i == _totalElements - 1;
        }
        bool outOfBounds() {
            if(_r < 0 || _c < 0 || _r >= _mat.size() || _c >= _mat.front().size()){
                return true;
            }
            return false;
        }
        bool _goingUp = true;
        void moveWithDirection() {
            if(_goingUp) {
                _r--;
                _c++;
            } else {
                _r++;
                _c--;
            }
        }
        void recover() {
            if(outOfBounds()) {
                if(_goingUp) {
                    _r++;
                    if(outOfBounds()){
                        _r++;
                        _c--;
                    }
                } else {
                    _c++;
                    if(outOfBounds()) {
                        _c++;
                        _r--;
                    }
                }
                _goingUp = !_goingUp;
            }
        }
    public:
        SpiralTraverser(const vector<vector<T>>& mat) : _mat(mat) {
            _totalElements = mat.size() * mat.front().size();
        }
        int I() const {
            return _i;
        }
        T CurVal() const {
            return _mat[_r][_c];
        }

        bool Advance() {
            if(atEnd()) {
                return false;
            }
            moveWithDirection();
            recover();
            _i++;
            return true;
        }
    };
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res(mat.size() * mat.front().size());
        SpiralTraverser traverser(mat);
        res[0] = traverser.CurVal();
        while(traverser.Advance()) {
            int i = traverser.I();
            int val = traverser.CurVal();
            res[i] = val;
        }
        return res;
    }
};