class Solution {
public:
    int greedy(string s) {
        /*
            Hint 1: Traverse the string from left to right.
            Hint 2: Keep a counter for the number of 'b' characters seen so far.
            Hint 3: An 'a' appearing after a 'b' makes the string unbalanced.
            Hint 4: Fix this greedily by deleting one earlier 'b'.
            Hint 5: Count each such fix as one deletion; the final count is the
           answer.
        */
        int countB = 0;
        int ans = 0;
        for (auto i : s) {
            if (i == 'b') {
                countB++;
            } else {
                if (countB > 0) {
                    countB--;
                    ans++;
                }
            }
        }
        return ans;
    }
    int minimumDeletions(string s) { return greedy(s); }
};