class Solution {
public:
    /*
        1 = [1]
        2 = [10]
        3 = [11]
        4 = [100]
        5 = [101]
        6 = [110]
        7 = [111]
        8 = [1000]

        From above we can observe that on every power of 2
        we are using 1 more bits
        For concatenations->
        left shift to no. of ongoing bits then add curr no
        Do module while adding up to avoid overflow
        for power of 2 -> n&(n-1)==0 or
        use factor which get 2x when i == factor
        ex. start with f = 2, bits = 1, ans = 0
        i = 1
            => ans = (0<<1) + i = 00 + 1 = 1
        i = 2 (bits++ | f = 4)
            => ans = (ans<<2) + i = 100 + 10 = 110
        i = 3
            => ans = (ans<<2) + i = 11000 + 11 = 11011
        i = 4 (bits++ | f=4)
            => ans = (ans<<4) + i = 11011000 + 100 = 11011100
    */
    int concatenatedBinary(int n) {
        long long ans = 0, bitsCount = 1, mod = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            if (i > 1 && (i & (i - 1)) == 0) { // [i&(i-1)==0] - power of 2
                bitsCount++;
            }
            // either do + or | as bits are 0 while concatenation
            ans = ((ans << bitsCount) + i) % mod; // concatenate with i
        }
        return (int)ans;
    }
};