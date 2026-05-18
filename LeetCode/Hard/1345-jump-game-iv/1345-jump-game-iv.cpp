class Solution {
public:
    // time: O(n*n)
    // space: O(n) [aux]
    int rec(vector<int>& arr, int index, vector<bool>& vis) {
        int n = arr.size();
        if (index < 0 || index >= n) {
            return INT_MAX;
        }
        if (index == n - 1) {
            return 0;
        }
        int ans = INT_MAX;

        // right
        int i = index;
        if (i + 1 < n && !vis[i + 1]) {
            vis[i + 1] = 1;
            int r = rec(arr, i + 1, vis);
            if (r != INT_MAX)
                ans = min(ans, 1 + r);
            vis[i + 1] = 0;
        }

        // left
        i = index;
        if (i - 1 >= 0 && !vis[i - 1]) {
            vis[i - 1] = 1;
            int l = rec(arr, i - 1, vis);
            if (l != INT_MAX)
                ans = min(ans, 1 + l);
            vis[i - 1] = 0;
        }

        // valid places other than index
        for (int i = 0; i < n; i++) {
            if (i != index && arr[i] == arr[index] && !vis[i]) {
                vis[i] = 1;
                int s = rec(arr, i, vis);
                if (s != INT_MAX)
                    ans = min(ans, 1 + s);
                vis[i] = 0;
            }
        }
        return ans;
    }

    // time: O(n) with clearing posMap after visiting all valid index
    // time: O(n*n) without clearing posMap [extra n for loop all index]
    // space: O(n)
    int graphBFS(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> posMap;
        // map[elem] = [all indexes with elem]
        for (int i = 0; i < n; i++) {
            posMap[arr[i]].push_back(i);
        }
        // vis map
        vector<bool> vis(n, 0);
        // bfs queue
        queue<int> q;
        // push 1st
        q.push(0);
        vis[0] = 1;
        // ans
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            // explore all same depth elems before moving deeper
            for (int j = 0; j < size; j++) {
                // index
                auto v = q.front();
                q.pop();
                // check if reached end then return steps
                if (v == n - 1) {
                    return steps;
                }
                // add all non-vis index with elems
                for (auto i : posMap[arr[v]]) {
                    if (!vis[i]) {
                        q.push(i);
                        vis[i] = 1;
                    }
                }

                // NOTE IMP: clear all path explored from map
                // this ensure re-scanning of vis indices
                // ex - arr[7 7 7 7 7 7]
                // posMap[7] - [0 1 2 3 4 5]
                // q = {0}
                // q = {1 2 3 4 5}
                // with next iterations we will still loop all elems
                // as we loop on posMap[7] so time = O(n*n) in worst
                // while after visiting all index of arr[v]
                // we can remove it directly
                // posMap[7] - [0 1 2 3 4 5]
                // q = {0}
                // q = {1 2 3 4 5} // remove all posMap[7]
                // so time = O(n) now
                posMap[arr[v]].clear();

                // add non-vis right
                if (v + 1 < n && !vis[v + 1]) {
                    q.push(v + 1);
                    vis[v + 1] = 1;
                }
                // add non-vis left
                if (v - 1 >= 0 && !vis[v - 1]) {
                    q.push(v - 1);
                    vis[v - 1] = 1;
                }
            }
            // increase steps
            steps++;
        }
        return steps;
    }
    int minJumps(vector<int>& arr) {
        // vector<bool> vis(arr.size(), 0);
        // return rec(arr, 0, vis);

        return graphBFS(arr);
    }
};