class Solution {
public:
    /*
    num = 5 (101)
    mask = 111
    111 ^ 101 = 010
    */
    int bitMask(int num){
         int mask = 1;

        while (mask <= num)
            mask <<= 1;

        return (mask - 1) ^ num;
    }
    int bitwiseComplement(int n) {
        if(n == 0 || n == 1){
            return !n;
        }
        return bitMask(n);   
    }
};