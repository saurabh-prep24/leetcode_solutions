class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0, j=0, ans=0;
        while(i<g.size()){
            while(j<s.size() && g[i]>s[i]){
                j++;
            }
            if(j<s.size()){
                ans++;
            }else{
                break;
            }
            i++;
            j++;
        }
        return ans;
    }
};