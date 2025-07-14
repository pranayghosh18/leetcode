class Solution {
    public int maximalSquare(char[][] matrix) {
        // ArrayList<ArrayList<Integer>> grid = new ArrayList<>();
        int[][] grid = new int[matrix.length][matrix[0].length];
        int res = 0;
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix[0].length; j++){
                int cell = matrix[i][j] - '0';
                if(i == 0 || j == 0) grid[i][j] = cell;
                else {
                    if(cell == 1) grid[i][j] = 1 + Math.min(grid[i-1][j], Math.min(grid[i][j-1], grid[i-1][j-1]));
                }
                res = Math.max(res, grid[i][j]);
            }
        }
        return res*res;    
    }
}