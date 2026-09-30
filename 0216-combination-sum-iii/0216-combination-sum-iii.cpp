class Solution {
    void find(int k, int n, int i,
              vector<vector<int>> &ans,
              vector<int> &ds) {
        if (k == 0) {
            if (n == 0)
                ans.push_back(ds);
            return;
        }
        for (int x = i; x <= 9; x++) {
            if (x > n)
                break;
            ds.push_back(x);
            find(k - 1, n - x, x + 1, ans, ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        find(k, n, 1, ans, ds);
        return ans;
    }
};