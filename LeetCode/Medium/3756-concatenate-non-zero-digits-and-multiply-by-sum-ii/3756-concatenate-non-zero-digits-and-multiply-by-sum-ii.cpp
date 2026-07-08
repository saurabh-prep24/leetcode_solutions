class Solution {
public:
    int mod = 1e9 + 7;
    vector<long long> pow10;

    // time: O(n)
    int solve(string s, int start, int end) {
        long long sum = 0, n = 0;
        for (int i = start; i <= end; i++) {
            char c = s[i];
            if (c != '0') {
                int d = c - '0';
                sum += d;
                n = (n * 10 + d) % mod;
            }
        }
        return (sum * n) % mod;
    }

    // time: O(n * q)
    // space: O(1)
    vector<int> brute(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            ans.push_back(solve(s, start, end));
        }
        return ans;
    }

    struct node {
        long long sum, num, len;
        node(long long s = 0, long long n = 0, long long l = 0) {
            sum = s;
            num = n;
            len = l;
        }
    };

    node merge(node L, node R) {
        return node((L.sum + R.sum) % mod, (L.num * pow10[R.len] + R.num) % mod,
                    L.len + R.len);
    }
    void buildSegTree(string& s, int i, int l, int r, vector<node>& segTree) {
        if (l == r) {
            int d = s[l] - '0';
            if (d == 0)
                segTree[i] = node(0, 0, 0);
            else
                segTree[i] = node(d, d, 1);
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegTree(s, 2 * i + 1, l, mid, segTree);
        buildSegTree(s, 2 * i + 2, mid + 1, r, segTree);

        node left = segTree[2 * i + 1];
        node right = segTree[2 * i + 2];

        segTree[i] = merge(left, right);
    }

    node solveRange(int start, int end, int i, int l, int r,
                    vector<node>& segTree) {
        if (r < start || l > end) {
            return node(0, 0, 0);
        }

        if (start <= l && r <= end) {
            return segTree[i];
        }

        int mid = (l + r) / 2;
        node left = solveRange(start, end, 2 * i + 1, l, mid, segTree);
        node right = solveRange(start, end, 2 * i + 2, mid + 1, r, segTree);

        return merge(left, right);
    }
    /*
        time: O(n)[buildSeg] + O(log n)[solveSeg]*O(q) = O(q logn)
        space: O(4n)
    */
    vector<int> segSolve(string& s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> ans;
        vector<node> segTree(4 * n);

        // pre-compute pow10
        pow10.assign(n + 1, 0);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % mod;

        // build seg tree
        buildSegTree(s, 0, 0, n - 1, segTree);

        for (auto i : queries) {
            int s = i[0], e = i[1];
            node t = solveRange(s, e, 0, 0, n - 1, segTree);
            int currAns = (t.num * t.sum) % mod;
            ans.push_back(currAns);
        }
        return ans;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        // return brute(s, queries);
        return segSolve(s, queries);
    }
};