class Solution {
    public int numberOfBoomerangs(int[][] points) {
        HashMap<Integer, HashMap<Integer, Integer>> map = new HashMap<>();
        for(int i = 0; i < points.length; i++) {
            for(int j = 0; j < points.length; j++) {
                if(i == j) {
                    continue;
                }

                int distance = 0;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int xDelta = Math.abs(x1 - x2);
                int yDelta = Math.abs(y1 - y2);
                
                distance += xDelta * xDelta;
                distance += yDelta * yDelta;


                HashMap<Integer, Integer> pointMap = map.getOrDefault(i, new HashMap<Integer, Integer>());

                int ps = pointMap.getOrDefault(distance, 0);

                ps++;

                pointMap.put(distance, ps);
                map.put(i, pointMap);
            }
        }

        int total = 0;

        for(HashMap<Integer, Integer> dists : map.values()) {
            for(Integer l : dists.values()) {
               
                total += l * (l - 1);
            }
        }

        return total;
    }
}