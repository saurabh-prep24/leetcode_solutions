class Solution {
public:
    string solveLPS(string s){
        int n=s.size();
        vector<int> lps(n,0);
        int len = 0, i=1;
        while(i<n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len > 0){
                    len = lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        int last = lps[n-1];
        return s.substr(0, last);
    }
    string longestPrefix(string s) {
        return solveLPS(s);
    }
};