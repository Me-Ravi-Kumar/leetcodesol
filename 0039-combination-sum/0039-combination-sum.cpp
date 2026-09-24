class Solution {
    vector<vector<int>> ans;

    void sum(vector<int>& candidates, vector<int>& ds,
             int target, int l, int h) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        if (l > h || target < 0) {
            return;
        }
        ds.push_back(candidates[l]);
        sum(candidates, ds, target - candidates[l], l, h);
        ds.pop_back();
        sum(candidates, ds, target, l + 1, h);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;

        sum(candidates, ds, target, 0, candidates.size() - 1);

        return ans;
    }
};