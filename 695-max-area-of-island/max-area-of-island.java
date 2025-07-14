class Solution {
public int maxAreaOfIsland(int[][] grid) {
        int maxArea = 0;
        Queue<Map.Entry<Integer, Integer>> bfs = new ArrayDeque();
        int[] dirs = {-1, 0, 1, 0, -1};
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[0].length; j++){
                if(grid[i][j] == 1){
                    int captured = 1;
                    bfs.add(new java.util.AbstractMap.SimpleEntry<>(i, j));
                    grid[i][j] = 0;
                    while (!bfs.isEmpty()) {
                        Map.Entry<Integer, Integer> top = bfs.poll();
                        // validate and push
                        for(int d=0; d<dirs.length-1; d++){
                            int x = top.getKey() + dirs[d];
                            int y = top.getValue() + dirs[d+1];

                        if( x >= 0 && x <grid.length && 
                            y >= 0 && y < grid[0].length &&
                            grid[x][y] == 1) {
                                bfs.add(new java.util.AbstractMap.SimpleEntry<>(x,y));
                                grid[x][y] = 0;
                                captured++;
                            }
                        } 
                    }
                    maxArea = Math.max(maxArea, captured);
                }
            }
        }
        return maxArea;
    }
}