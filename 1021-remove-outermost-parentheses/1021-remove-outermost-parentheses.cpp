class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string res;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' && cnt == 0) {
                cnt++;
            }
            else if (s[i] == '(' && cnt > 0) {
                res.push_back(s[i]);
                cnt++;
            }
            else if (s[i] == ')' && cnt > 1) {
                res.push_back(s[i]);
                cnt--;
            }
            else if (s[i] == ')' && cnt == 1) {
                cnt--;
            }
        }
        return res;
    }
};