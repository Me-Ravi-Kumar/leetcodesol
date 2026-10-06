class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int cnt1 = 0;
        int cnt2 = 0; 
        int i = 0;

        while(n--) {
            if(s[i] == '(') {
                cnt1++;
            }
            else if(cnt1 == 0 && s[i] == ')') {
                cnt2++;
            }
            else {
                cnt1--;
            }

            i++;
        }

        return cnt1 + cnt2;
    }
};