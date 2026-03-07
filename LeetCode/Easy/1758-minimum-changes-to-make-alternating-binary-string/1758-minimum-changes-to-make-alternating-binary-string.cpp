class Solution {
public:
    int calcOps(string s, char first) {
        int ans = 0;
        // change first  char
        if (s[0] != first) {
            ans++;
            s[0] = first;
        }
        // check rest of str
        for (int i = 1; i < s.size(); i++) {
            // if curr same as prev then change and update ans
            if (s[i - 1] == s[i]) {
                s[i] = !(s[i - 1] - '0') + '0';
                ans++;
            }
        }
        // return ans
        return ans;
    }
    // two possible solutions:
    // first char as 0 then 01010...
    // first char as 1 then 10101...
    // we need to solve for both one
    // so min ops can be our ans
    // time: O(N)
    // space: O(1)
    int brute(string s) {
        // return min of s with s[0]=0 and then s[0]=1
        return min(calcOps(s, '0'), calcOps(s, '1'));
    }

    // similar to brute force approach
    // we can use XOR for each index to check parity of elem
    // ex - 0 1 2 3 4 5 6
    // par- 0 1 0 1 0 1 0 (i&1)
    // then doing XOR with elem will tell if we need to invert or not
    // if (i&1) ^ (elem&1) == 0 then both are same - no ops
    // else change so add ops
    // (i&1) ^ (elem & 1) = (i^elem) & 1 in simple terms
    // ---
    // then invert parity for each index then calc again
    // this ensures min ans
    int binaryParityUsingXOR(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((i ^ s[i]) & 1) {
                // parity not matching as xor = 1 so update ans for flip
                ans++;
            }
        }
        // NOTE:::
        // if we have one flip as ans then n-ans will reflect
        // changing all other elem which were changed with ans
        int n = s.size();
        return min(ans, n - ans);
    }
    int minOperations(string s) {
        return brute(s);
        // return binaryParityUsingXOR(s);
    }
};