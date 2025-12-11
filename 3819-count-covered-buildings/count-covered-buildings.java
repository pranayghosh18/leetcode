class Solution {

    public int countCoveredBuildings(int n, int[][] buildings) {
        HashMap<Integer, TreeSet<Integer>> xCordToYPoints = new HashMap<>();
        HashMap<Integer, TreeSet<Integer>> yCordToXPoints = new HashMap<>();

        for (int[] loc : buildings) {
            int x = loc[0];
            int y = loc[1];

            // xCordToYPoints.getOrDefault(x, new TreeSet<>())
            //               .add(y);
            if (xCordToYPoints.get(x) == null) {
                xCordToYPoints.put(x, new TreeSet<>());
            }

            xCordToYPoints.get(x).add(y);
            // yCordToXPoints.getOrDefault(y, new TreeSet<>())
            //               .add(x);
            if (yCordToXPoints.get(y) == null) {
                yCordToXPoints.put(y, new TreeSet<>());
            }
            
            yCordToXPoints.get(y).add(x);
        }
        

////////////////////////////////////////////////////////////////

        // for (Map.Entry<Integer, TreeSet<Integer>> entry : xCordToYPoints.entrySet()) {
        //     System.out.println("key " + entry.getKey());
        //     System.out.println(entry.getValue());
        // }

        // for (Map.Entry<Integer, TreeSet<Integer>> entry : yCordToXPoints.entrySet()) {
        //     System.out.println("key " + entry.getKey());
        //     System.out.println(entry.getValue());
        // }

///////////////////////////////////////////////////////////////////



        int ans = 0;
         for (int[] loc : buildings) {
            int x = loc[0];
            int y = loc[1];

            if (xCordToYPoints.get(x).higher(y) != null &&
                xCordToYPoints.get(x).lower(y) != null &&
                yCordToXPoints.get(y).higher(x) != null &&
                yCordToXPoints.get(y).lower(x) != null
            ) ans++;
        }
        
        return ans;
    }
}