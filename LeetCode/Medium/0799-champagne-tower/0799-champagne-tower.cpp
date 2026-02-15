class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> curr(1, 0);
        curr[0] = poured;
        for(int i =0;i<query_row;i++){
            vector<double>next(i+2, 0);
            for(int j=0;j<=i;j++){
                if(curr[j] > 1){
                    double excess = (curr[j]-1)/2;
                    next[j]+=excess;
                    next[j+1]+=excess;
                }
            }
            curr = next;
        }

        return curr[query_glass] > 1 ? 1 : curr[query_glass];
    }
};