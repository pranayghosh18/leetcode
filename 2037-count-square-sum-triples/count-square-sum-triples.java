class Solution {

    int gcd(int a, int b) {
        if (a < b) return gcd(b,a);
        if (b == 0) return a;
        return gcd(b, a%b);
    }
    int addOn (int x, int n) {
        int res = 0;
        int counter = 1;
        while (x * counter <= n) {
            res++;
            counter++;
        }
        return res;
    }

    public int countTriples(int n) {
        int ans = 0;
        // int odd = 1, even = 2;
        for (int odd=1; odd<n; odd+=2) {
            int maxNum = 0;
            for (int even=2; maxNum<n; even+=2) {
                maxNum = odd*odd + even*even;
                if (gcd(odd, even) == 1) {
                    // System.out.println("even " + even + " odd " + odd);
                    ans += addOn(maxNum, n);
                }
            }
        }
        return 2 * ans;
    }
}