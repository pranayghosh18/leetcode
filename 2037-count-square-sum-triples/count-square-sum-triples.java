class Solution {

    class GetSquares {
        List<Boolean> squares;
        public GetSquares(int n) {
            squares = new ArrayList<>(Collections.nCopies(n+1, false));
            int endIndex = (int) Math.sqrt(n);
            for (int i=0; i<=endIndex; i++) {
                int squareVal = i*i;
                squares.set(squareVal, true);
            }
        }
        
        public boolean isSquare(int x) {
            return squares.get(x);
        }
    }
    
    public int countTriples(int n) {
        GetSquares squares = new GetSquares(n*n);
        int ans = 0;

        for (int c=2; c<=n; c++) {
            for (int b=c-1; b>=1; b--) {
                int require = c*c - b*b;
                if (squares.isSquare(require)) ans++;
            }
        }
        
        return ans;
    }
}

/**
a < b < c

for each c,

traverse through b and check if a can be there
isSquare


 */