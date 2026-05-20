class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        // all elems are [1...n] only with no repetitions
        vector<int> counts(n + 1, 0);
        // count duplicates from start
        int dup = 0;
        for (int i = 0; i < n; i++) {
            counts[A[i]]++;
            // check if count > 1
            if (counts[A[i]] > 1) {
                dup++;
            }
            counts[B[i]]++;
            // check if count > 1
            if (counts[B[i]] > 1) {
                dup++;
            }
            // cout << dup << endl;
            ans[i] = dup;
        }
        return ans;
    }
};