class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        string t = "";
        for(auto i: s){
            if(i == ' ' && t!=""){
                ans++;
                t = "";
            }else if (i != ' '){
                t += i;
            }
        }
        if(t != "")
            ans++;
        return ans > 0 ? ans : 0;
    }
};