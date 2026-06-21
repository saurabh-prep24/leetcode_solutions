class Solution {
public:
    // time: O(n logn)
    int sortSolve(vector<int>& costs, int coins) {
        int ans = 0;
        // sort to buy smaller coins first
        sort(costs.begin(), costs.end());
        for (int i = 0; i < costs.size(); i++) {
            // check if buy possible
            if (coins - costs[i] >= 0) {
                // buy
                ans += 1;
                // reduce coins
                coins -= costs[i];
            } else {
                // no further buy so exit
                break;
            }
        }
        return ans;
    }

    // time: O(n)
    // space: O(n)
    int countsortSolve(vector<int>& costs, int coins) {
        int ans = 0;
        vector<int> count(1e5 + 1, 0);
        for (auto i : costs) {
            count[i]++;
        }

        for (int cost = 1; cost < count.size(); cost++) {
            if (count[cost] > 0) {
                // if any buy possible with curr cost
                if (coins - cost >= 0) {
                    // buy either all coins with cost 
                    // or partial on remaining coins
                    int buy = min(count[cost], coins / cost);
                    // reduce coins
                    coins -= buy * cost;
                    // add no. of coins
                    ans += buy;
                } else {
                    // no further buy so exit
                    break;
                }
            }
        }
        return ans;
    }
    int maxIceCream(vector<int>& costs, int coins) {
        // return sortSolve(costs, coins);
        return countsortSolve(costs, coins);
    }
};