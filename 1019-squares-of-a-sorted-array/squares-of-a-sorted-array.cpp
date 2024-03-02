class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(int& i : A)
            {
                if(i < 0)
                    i*=-1;
            }
        sort(A.begin(), A.end());
        for(int& i : A)
            i*=i;
        return A;
    }
};