class Solution {
    public int specialTriplets(int[] nums) {
        List<Integer> leftX2 = new ArrayList<>();
        List<Integer> rightX2 = new ArrayList<>();   
        // fill the req vals
        Map<Integer, Integer> counter = new HashMap<>();
        for (int i=0; i<nums.length; i++) {
            int x2 = nums[i] * 2;
            leftX2.add(counter.getOrDefault(x2, 0));
            counter.put(nums[i], 
                        counter.getOrDefault(nums[i], 0) + 1); 
        }

// System.out.println(counter);

        counter.clear();

// System.out.println(counter);

        for (int i=nums.length-1; i>=0; i--) {
            int x2 = nums[i] * 2;
            rightX2.add(counter.getOrDefault(x2, 0));
            counter.put(nums[i], 
                        counter.getOrDefault(nums[i], 0) + 1); 
            
        }
        Collections.reverse(rightX2);

        // System.out.println(leftX2);
        // System.out.println(rightX2);

        int ans = 0;
        int mod = 1_000_000_007;
        for (int i = 0; i < nums.length; i++) {
            long contrib = ((long) leftX2.get(i) * rightX2.get(i)) % mod;
            ans = (int)((ans + contrib) % mod);
        }

        return ans;
    }
}