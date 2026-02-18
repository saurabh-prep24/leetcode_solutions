class Solution {
public:
    bool trick(int n) {
        /*
        If bits are alternating:
        n      = 101010
        n>>1   = 010101
        XOR    = 111111
        So x becomes all 1s.
        And a number that is all 1s satisfies:
        x & (x + 1) == 0
        Example:
        111111
        +    1
        ------
        1000000
        ------

        AND = 0
         111111
        1000000
        -------
        0000000
        -------
        */
        unsigned int temp = n ^ (n >> 1);
        return (temp & (temp + 1)) == 0;
    }
    bool hasAlternatingBits(int n) {
        return trick(n);

        // check first set bit
        bool isSetBit = n & 1;
        // loop
        while (n) {
            // check if curr bit is same as isSetBit flag
            if ((n & 1) != isSetBit)
                // not matched then return false
                return 0;

            // toggle isSetBit flag for alternating condition
            isSetBit = !isSetBit;

            // right shift for next bit value
            n = n >> 1;
            // cout << n << " " << (n&1)<<" "<<isSetBit << endl;
        }
        // all bit are alternating return true
        return 1;
    }
};