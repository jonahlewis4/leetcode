class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        HashMap<Character, Integer> count = new HashMap<>();
        for(char c : p.toCharArray()) {
            count.put(c, count.getOrDefault(c, 0) + 1);
        }

        List<Integer> res = new ArrayList<>();

        HashMap<Character, Integer> count2 = new HashMap<>();
        int matching = 0;
        
        for(int i = 0; i < s.length(); i++) {
            char newC = s.charAt(i);

            count2.put(newC, count2.getOrDefault(newC, 0) + 1);

            int trueCount = count.getOrDefault(newC, 0);
            int curCount = count2.get(newC);
            if(trueCount > 0) {
                if(curCount == trueCount) {
                    matching++;
                }
                if(curCount == trueCount + 1) {
                    matching--;
                }
            }
            

            if(i - p.length() >= 0) {
                char oldC = s.charAt(i - p.length());
                count2.put(oldC, count2.getOrDefault(oldC, 0) - 1);
                trueCount = count.getOrDefault(oldC, 0);
                curCount = count2.get(oldC);
                if(trueCount > 0) {
                    if(curCount == trueCount) {
                        matching++;
                    }

                    if(curCount == trueCount - 1) {
                        matching--;
                    }
                }
            }
            
            if(matching == count.size()) {
                res.add(i - p.length() + 1);
            }
        }
        return res;
    }
}