class Solution {
    bool palindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    void solve(string s, int low, int high, vector<string>& ds,vector<vector<string>>& result) {

        if (low == s.length()) {
            result.push_back(ds);
            return;
        }

        for (int i = low; i <= high; i++) {

            string temp = s.substr(low, i - low + 1);

            if (palindrome(temp)) {

                ds.push_back(temp);

                solve(s, i + 1, high, ds, result);

                ds.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;
        vector<string> ds;

        solve(s, 0, s.length() - 1, ds, result);

        return result;
    }
};