class Solution {
public:
    typedef unsigned long long ull;
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        vector<vector<ull>> dp(m + 1, vector<ull>(n + 1));
        for (int row = 0; row < m + 1; row++) {
            dp[row][0] = 1;
        }

        for (int col = 1; col < n + 1; col++) {
            dp[0][col] = 0;
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[m][n];
    }
};
