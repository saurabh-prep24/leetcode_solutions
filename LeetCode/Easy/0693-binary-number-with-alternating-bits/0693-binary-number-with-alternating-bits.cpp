class Solution {
public:
    bool hasAlternatingBits(int n) {
        // check first set bit
        bool isSetBit = n & 1;
        // loop
        while (n) {
            // check if curr bit is same as isSetBit flag
            if ((n&1) != isSetBit)
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