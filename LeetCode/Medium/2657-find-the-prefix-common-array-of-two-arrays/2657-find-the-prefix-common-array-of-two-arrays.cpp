class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        vector<int> countA(51, 0);
        vector<int> countB(51, 0);
        for (int i = 0; i < n; i++) {
            countA[A[i]]++;
            countB[B[i]]++;
            int t = 0;
            for (int j = 0; j < countA.size(); j++) {
                t += min(countA[j], countB[j]);
            }
            ans[i] = t;
        }
        return ans;
    }
};