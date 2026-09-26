class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        string ans = "";

        unordered_map<string, string> mp;

        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }

        bool isopen = false;
        string temp = "";

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                isopen = true;
                temp = "";
            }
            else if (s[i] == ')') {
                isopen = false;

                if (mp.find(temp) != mp.end())
                    ans += mp[temp];
                else
                    ans += "?";

                temp = "";
            }
            else {
                if (isopen)
                    temp += s[i];
                else
                    ans += s[i];
            }
        }

        return ans;
    }
};