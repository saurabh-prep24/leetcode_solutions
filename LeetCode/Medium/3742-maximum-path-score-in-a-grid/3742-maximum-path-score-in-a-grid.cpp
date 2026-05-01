class Solution {
public:
    int cost(int x) { return x > 0; }

    void recSolve(vector<vector<int>>& grid, int& k, int n, int m, int x, int y,
                  int currScore, int currCost, int& maxScore) {

        currScore += grid[x][y];
        currCost += cost(grid[x][y]);

        if (currCost > k)
            return;

        // destination
        if (x == n - 1 && y == m - 1) {
            maxScore = max(maxScore, currScore);
            return;
        }

        // right
        if (y + 1 < m) {
            recSolve(grid, k, n, m, x, y + 1, currScore, currCost, maxScore);
        }

        // down
        if (x + 1 < n) {
            recSolve(grid, k, n, m, x + 1, y, currScore, currCost, maxScore);
        }
    }

    int recSolveMemo(vector<vector<int>>& grid, int k,
                     vector<vector<vector<int>>>& dp, int x, int y, int n,
                     int m) {
        // invalid
        if (x >= n || y >= m) {
            return -1;
        }

        int c = cost(grid[x][y]);
        if (c > k)
            return -1;

        if (x == n - 1 && y == m - 1) {
            // score at last cell
            return dp[x][y][k]=grid[x][y];
        }

        // already calc so return
        if (dp[x][y][k] != INT_MIN) {
            return dp[x][y][k];
        }

        // move right
        int right = recSolveMemo(grid, k - c, dp, x, y + 1, n, m);
        // move down
        int down = recSolveMemo(grid, k - c, dp, x + 1, y, n, m);
        // get max score
        int maxi = max(right, down);
        // if -1 then return
        if (maxi == -1) {
           return dp[x][y][k] = -1;
        }
        // add curr score in maxi
        return dp[x][y][k] = grid[x][y] + maxi;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        // int ans = -1;
        // int n = grid.size(), m = grid[0].size();

        // recSolve(grid, k, n, m, 0, 0, 0, 0, ans);
        // return ans;

        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, INT_MIN)));
        int ans = recSolveMemo(grid, k, dp, 0, 0, n, m);
        return ans != INT_MIN ? ans : -1;
    }
};