class Solution {
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    void go(int node, int[][] graph, int end, List<Integer> build) {
        build.add(node);
        if(node == end) {
            res.add(new ArrayList(build));
        } else {
            for(int i = 0; i < graph[node].length; i++) {
                int nei = graph[node][i];
                go(nei, graph, end, build);
            }
        }

        build.remove(build.size() - 1);
    }
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int end = graph.length - 1;
        List<Integer> build = new ArrayList<Integer>();
        go(0, graph, end, build);
        return res;
    }
}