class Solution {
public:
    // time: O(n)
    // space: O(1) but overflow as 500 dig can't be stored directly
    int convert(string s) {
        unsigned long long a = 0;
        int i = s.size() - 1;
        unsigned long long int f = 1; // 2 places
        while (i >= 0) {
            a = a + f * (s[i] - '0');
            i--;
            f *= 2;
        }
        int ans = 0;
        while (a != 1) {
            if (a & 1) {
                a += 1;
            } else {
                a = a / 2;
            }
            ans++;
        }

        return ans;
    }

    // time: O(n)
    // space: O(1)
    int processEachBit(string s) {
        // consider
        // 100 -> 4 => ans = +1(/2) +1(/2) -> 2 [reached 1]
        // whenever there is last bit not set
        // then only 1 operation /2 -> right shift

        // 101 -> 5 => ans = +1(odd + 1)
        // 110 -> 6 => ans = +1(/2) [right shift]
        // 011 -> 3 => ans = +1(add 1)
        // 100 -> 4 => ans = +1(/2)
        //  10 -> 2 => ans = +1(/2)
        //   1 -> 1 => ans = +1(/2) [reached 1]
        // so whenever there last bit is set then we are carrying 1 due to sum
        // and then divide by 2 as it got even -> which right shifts

        // MSB[most sig bit] can be skipped at last to get 1

        int ans = 0;
        int carry = 0;
        for (int i = s.size() - 1; i > 0; i--) {
            int currBit = s[i] - '0' + carry;
            if (currBit == 1) {
                // odd
                ans += 2;
                carry = 1;
            } else {
                ans += 1;
            }
        }
        // process last carry also so divide by 2 [since last dig rem = 1]
        // 1+carry = 1 + 1 = 2 [10] => div by 2 => 1
        if (carry) {
            ans++;
        }
        return ans;
    }

    int numSteps(string s) {
        // runtime err as overflow since len is <=500 even
        // long long can't store it [cap for unsigned long long
        // -> 0 to 2^(64)−1) ~ 64 digits]
        // return convert(s);

        return processEachBit(s);
    }
};