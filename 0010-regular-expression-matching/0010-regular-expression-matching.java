class Solution {
    String _s;
    String _p;
    HashMap<Integer, HashMap<Integer, Boolean>> cache = new HashMap<>();
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
        
        HashMap<Integer, Boolean> in = cache.get(sI);
        if(in == null) {
            cache.put(sI, new HashMap<Integer, Boolean>());
            in = cache.get(sI);
        }

        Boolean in2 = in.get(pI);
        if(in2 != null) {
            return in2;
        }

        if(starAfter(pI)){
            boolean res = false;
            if(matches(sI, pI)){
                res |= match(sI + 1, pI);
            }
            res |= match(sI, pI + 2);
            in.put(pI, res);
            return res;
        }
        if(matches(sI, pI)) {
            in.put(pI, match(sI + 1, pI + 1));
            return in.get(pI);
        }
        return false;

    }
    public boolean isMatch(String s, String p) {
        _s = s;
        _p = p;

        return match(0,0);
    }
    

}