class Solution {
public:
    // time: O(32)
    int simple(int n) {
        int s = 0;
        while (n) {
            s += n & 1;
            n = n >> 1;
        }
        return s;
    }

    // time: O(setBitsCount)
    int opt(int n) {
        int s = 0;
        while (n) {
            n = n & (n - 1);
            s++;
        }
        return s;
    }
    int hammingWeight(int n) {
        cout << simple(n) << endl;
        cout << opt(n) << endl;
        return opt(n);
    }
};