class Solution {
public:
    vector<int> xMoves = {0, 1, 0, -1};
    vector<int> yMoves = {1, 0, -1, 0};
    bool solveRec(vector<vector<int>>& grid, int health, int x, int y, int n,
                  int m, vector<vector<bool>>& vis) {
        // cout << x << " - " << y << " -> " << health << endl;

        // last node reached
        if (x == n - 1 && y == m - 1) {
            if (health >= 1) {
                // if last cell is again 1 then handle health-1
                return health - grid[x][y] > 0;
            }
        }

        // mark visited
        vis[x][y] = 1;
        bool ans = 0;
        for (int i = 0; i < 4; i++) {
            // new x and y
            int xN = x + xMoves[i];
            int yN = y + yMoves[i];

            // check valid position for next cells
            // if health is valid on next cell then move in rec
            if (xN >= 0 && yN >= 0 && xN < n && yN < m && !vis[xN][yN] &&
                health - grid[x][y] > 0) {
                bool isSolved =
                    solveRec(grid, health - grid[x][y], xN, yN, n, m, vis);
                // update ans
                if (isSolved)
                    return ans = 1;
            }
        }
        // backtrack
        vis[x][y] = 0;
        // not possible
        return ans;
    }

    bool solveRecMemo(vector<vector<int>>& grid, int health, int x, int y,
                      int n, int m, vector<vector<bool>>& vis,
                      vector<vector<vector<int>>>& dp) {
        // last node reached
        if (x == n - 1 && y == m - 1) {
            if (health >= 1) {
                // if last cell is again 1 then handle health-1
                return dp[x][y][health] = health - grid[x][y] > 0;
            }
        }

        if (health >= 0 && dp[x][y][health] != -1) {
            return dp[x][y][health];
        }

        // mark visited
        vis[x][y] = 1;
        bool ans = 0;
        for (int i = 0; i < 4; i++) {
            // new x and y
            int xN = x + xMoves[i];
            int yN = y + yMoves[i];

            // check valid position for next cells
            // if health is valid on next cell then move in rec
            if (xN >= 0 && yN >= 0 && xN < n && yN < m && !vis[xN][yN] &&
                health - grid[x][y] > 0) {
                bool isSolved = solveRecMemo(grid, health - grid[x][y], xN, yN,
                                             n, m, vis, dp);
                // update ans
                if (isSolved)
                    return dp[x][y][health] = 1;
            }
        }
        // backtrack
        vis[x][y] = 0;
        // not possible
        return dp[x][y][health] = ans;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(health + 1, -1)));
        // return solveRec(grid, health, 0, 0, n, m, vis);
        return solveRecMemo(grid, health, 0, 0, n, m, vis, dp);
    }
};