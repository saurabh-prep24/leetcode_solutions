class Solution {
public:
    int add(char a, char b, int c){
        int s = c;
        if(a == b && a=='1'){
            s += 2;
        }else if(a == '1' || b == '1'){
            s += 1;
        }
        return s;
    }
    string addBinary(string a, string b) {
        string ans = "";
        // reverse both
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i =0, j=0, c=0;
        // loop each digits
        while(i<a.size() || j<b.size() || c>0){
            // if both then add with carry
            if(i<a.size() && j<b.size()){
                int t= add(a[i], b[j], c);
                ans += to_string(t%2);
                c = t/2;
                i++;
                j++;
            }else if(i<a.size()){
                int t= add(a[i], '0',c);
                c = t/2;
                ans += to_string(t%2);
                i++;
            }else if(j<b.size()){
                int t= add('0', b[j],c);
                c = t/2;
                ans += to_string(t%2);
                j++;
            }else if(c>0){
                // add carry finally
                ans += to_string(c);
                break;
            }
        }
        // reverse for actual ans
        reverse(ans.begin(), ans.end());
        return ans;
    }
};