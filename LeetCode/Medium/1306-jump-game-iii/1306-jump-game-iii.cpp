class Solution {
public:
    // Time:  O(n)
    // Space: O(n)
    // instead of vis we can also mark arr[start] as (-)
    // as arr[i]>0 given in ques so would work
    // so space can be avoided
    bool dfs(vector<int>& arr, int start, vector<bool>& vis) {
        if (start < 0 || start >= arr.size()) {
            return 0;
        }
        // return if already vis
        if (vis[start]) {
            return 0;
        }

        // mark vis
        vis[start] = 1;

        // return if 0
        if (arr[start] == 0) {
            return 1;
        }
        // return ans
        return dfs(arr, start + arr[start], vis) ||
               dfs(arr, start - arr[start], vis);
    }

    // Time:  O(n)
    // Space: O(n)
    bool bfs(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(start);
        vis[start] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (arr[node] == 0) {
                return true;
            }
            int add = node + arr[node];
            int sub = node - arr[node];
            // add jump
            if (add >= 0 && add < n && !vis[add]) {
                vis[add] = true;
                q.push(add);
            }
            // subtract jump
            if (sub >= 0 && sub < n && !vis[sub]) {
                vis[sub] = true;
                q.push(sub);
            }
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==0)
            return 1;

        // track vis
        // vector<bool> vis(arr.size(), 0);
        // return dfs(arr, start, vis);

        return bfs(arr, start);
    }
};