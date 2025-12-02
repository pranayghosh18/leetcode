class Solution {

        private long NC2(long n) {
            long ans = 1;
            long mod = 100_000_009;
            n %= mod;
            if (n % 2 == 0) {
                ans = n/2;
                ans *= (n-1);
            }
            else {
                ans = (n-1)/2;
                ans *= n;
            }

            return ans % mod;
        }

        private long nC2(long n) {
            long mod = 100_000_007;
            
            long a = n % mod;
            long b = (n - 1) % mod;

            long inv2 = (mod + 1) / 2;

            return (((a * b) % mod) * inv2) % mod;
        }


public int countTrapezoids(int[][] points) {
    long ans = 0;
    int MOD = 1_000_000_007;
    long INV2 = 500_000_004; // modular inverse of 2 mod 1e9+7

    Map<Integer, Long> y_points = new HashMap<>();
    for (int[] point : points) {
        int y = point[1];
        y_points.put(y, y_points.getOrDefault(y, 0L) + 1);
    }

    List<Long> segList = new ArrayList<>();
    for (long count : y_points.values()) {
        if (count >= 2) {
            long seg = count * (count - 1) / 2;
            segList.add(seg);
        }
    }

    long totalSeg = 0;
    long totalSq = 0;

    for (long seg : segList) {
        long m = seg % MOD;
        totalSeg = (totalSeg + m) % MOD;
        totalSq = (totalSq + m * m % MOD) % MOD;
    }

    long ansVal = (totalSeg * totalSeg % MOD - totalSq + MOD) % MOD;
    ansVal = ansVal * INV2 % MOD;

    return (int) ansVal;
}
}