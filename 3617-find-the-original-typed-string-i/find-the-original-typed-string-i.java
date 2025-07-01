class Solution {
    public static int possibleStringCount(String word) {
        // ArrayList<Integer> count = new ArrayList<>(word.length());
        // int counter[] = new int[word.length()];
        // System.out.println(count);
        // for(int i=0; i<word.length(); i++) count.add(0);
        // System.out.println(count);

        // count.add(0);
        int total = 1;
        for(int i=1; i<word.length(); i++){
            if(word.charAt(i) == word.charAt(i-1)) {
                // count.set(i, 1 + count.get(i-1));
                // counter[i] = counter[i-1] + 1;
                total++;
            }
        }
        // System.out.println(counter);
        // System.out.println(count);
        // int ans = 0;
        // int res = 0;
        // for(int t : counter) if(t > 0) res++;
        // for(int c : count) if(c>0) ans++;
        // return ans+1;
        // return res+1;
        return total;
    }

}