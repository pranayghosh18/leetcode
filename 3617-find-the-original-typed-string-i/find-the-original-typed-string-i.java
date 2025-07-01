class Solution {
    public static int possibleStringCount(String word) {
        ArrayList<Integer> count = new ArrayList<>(word.length());
        // System.out.println(count);
        for(int i=0; i<word.length(); i++) count.add(0);
        // System.out.println(count);

        // count.add(0);
        for(int i=1; i<word.length(); i++){
            if(word.charAt(i) == word.charAt(i-1)) {
                count.set(i, 1 + count.get(i-1));
            }
        }
        // System.out.println(count);
        int ans = 0;
        for(int c : count) if(c>0) ans ++;
        return ans+1;
    }
}