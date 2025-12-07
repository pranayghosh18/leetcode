class Solution {
    public int countCollisions(String directions) {
        ArrayList<Character> chars = new ArrayList<>();
        int ans = 0;

        for (int i=0; i<directions.length(); i++) {
            if (!chars.isEmpty() &&
                directions.charAt(i) == 'L' &&
                chars.get(chars.size()-1) == 'R')
            {
                chars.remove(chars.size()-1);
                chars.add('S');
                ans += 2;   
            }
            else {
                chars.add(directions.charAt(i));
            }
        }

        // process >>>>. cases
        int rightMovers = 0;
        for (int i=0; i<chars.size(); i++){
            if (chars.get(i) == 'R') rightMovers++;
            else if (chars.get(i) == 'S') {
                ans += rightMovers;
                rightMovers = 0;
            }
        }

        // process .<<< cases
        int leftMovers = 0;
        for (int i=chars.size()-1; i>=0; i--) {
            if (chars.get(i) == 'L') leftMovers++;
            else if (chars.get(i) == 'S') {
                ans += leftMovers;
                leftMovers = 0;
            }
        }

        return ans;
    }
}

/**
RLRSLL
>< > . < <, 0
> . < <, 2
. < <, 3
. <, 4
., 5

2
1. m >>>> in stack and . comes then ANS += m
2. at the end of process
    . <<<< n then ANS += n
after each --> iteration the string be  >>>>>>.<<<<<.>>>.<<<
3A. process >>>
3B. proces <<<

>>><>>>.

>>.>>>.
2 

ANS = 2 + 2 + 3

LLRR
<<>>



 */