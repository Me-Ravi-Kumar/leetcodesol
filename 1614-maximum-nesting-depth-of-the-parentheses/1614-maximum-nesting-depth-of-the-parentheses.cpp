class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count = 0;
        int i = 0;
        int n = s.length();

        while (i < n) {
            if (s[i] == '(') {
                count++;
                ans = max(ans, count);
            }

            if (s[i] == ')') {
                count--;
            }

            i++;
        }

        return ans;
    }
};