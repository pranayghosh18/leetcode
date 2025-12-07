class Solution {
    public int countOdds(int low, int high) {
        if ((low % 2 == 1) | (high % 2 == 1)) return (high - low + 2) / 2;
        if ((low % 2 == 0) | (high % 2 == 0)) return (high - low) / 2;
        return (high - low + 1) / 2;
    }
}

/**

e e ---> ceil( r-l-1 / 2 ) = r-l /2
e o ---> r-l+1 / 2
o e ---> r-l+1 / 2
o o ---> r-l+1 / 2


 */