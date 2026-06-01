class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // sort 
        sort(cost.begin(), cost.end());
        int ans = 0;
        int i = cost.size() - 1;
        while (i >= 0) {
            if (i >= 2) {
                // free is possible so reduce 3 places after updating ans
                ans += cost[i] + cost[i - 1];
                i -= 3;
            } else {
                // no free now just add rest cost directly
                ans += cost[i];
                i--;
            }
        }
        return ans;
    }
};