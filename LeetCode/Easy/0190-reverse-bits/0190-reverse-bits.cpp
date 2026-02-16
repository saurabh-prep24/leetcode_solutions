class Solution {
public:
    int reverseBits(int n) {
        // keep for ans
        int ans = 0;
        int i = 0;
        // while (i < 32) {
        //     // get last bit with &1
        //     int last_bit = n & 1;
        //     // add to ans with | and put to starting at (32-i) right shift
        //     ans = ans | (last_bit << (31 - i));
        //     // left shift bit of n to process next bit
        //     n = n >> 1;
        //     // increament i
        //     i++;
        // }

        while (i < 32) {
            // right shift ans to append bit to begining
            ans = ans << 1;
            // get last bit with &1
            int last_bit = n & 1;
            // add to ans with | and put to starting at (32-i) right shift
            ans = ans | last_bit;
            // left shift bit of n to process next bit
            n = n >> 1;
            // increament i
            i++;
        }
        return ans;
    }
};