class Solution {
    String _s;
    String _p;
    private boolean starAfter(int pI) {
        if(pI + 1 >= _p.length()) {
            return false;
        }
        return _p.charAt(pI + 1) == '*';
    }
    private boolean matches(int sI, int pI) {
        if(sI >= _s.length()) {
            return false;
        }

        char sC = _s.charAt(sI);
        char pC = _p.charAt(pI);
        if(pC == '.') {
            return true;
        }
        if(sC == pC) {
            return true;
        }
        return false;
    }
    private boolean match(int sI, int pI)  {
        if(sI == _s.length() && pI == _p.length()) {
            return true;
        }
        if(pI >= _p.length()) {
            return false;
        }
        
        if(starAfter(pI)){
            boolean res = false;
            if(matches(sI, pI)){
                res |= match(sI + 1, pI);
            }
            res |= match(sI, pI + 2);
            return res;
        }
        if(matches(sI, pI)) {
            return match(sI + 1, pI + 1);
        }
        return false;

    }
    public boolean isMatch(String s, String p) {
        _s = s;
        _p = p;

        return match(0,0);
    }
    

}