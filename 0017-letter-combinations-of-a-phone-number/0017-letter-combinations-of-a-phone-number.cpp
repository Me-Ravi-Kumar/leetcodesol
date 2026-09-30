class Solution {
    void find(string digits, int low, int high, string ds,vector<string>& result,unordered_map<char, string> &mp) {
          if(low>=high){
            result.push_back(ds);
            return;
          }
          char ch = digits[low];
          string str = mp[ch];

          for(int i=0;i<str.length();i++){
            ds.push_back(str[i]);
            find(digits,low+1,high,ds,result,mp);
            ds.pop_back();
          }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return {};
        }
        int n = digits.length();
        unordered_map<char, string> mp;

        char ch = 'a';

        for (char i = '2'; i <= '9'; i++) {

            int count = (i == '7' || i == '9') ? 4 : 3;

            for (int j = 0; j < count; j++) {
                mp[i] += ch;
                ch++;
            }
        }

        string ds = "";
        vector<string> result;

        find(digits,0,n,ds,result,mp);

        return result;
    }
};