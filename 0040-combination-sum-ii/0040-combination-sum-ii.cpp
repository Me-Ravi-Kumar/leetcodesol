class Solution {
    void combination(vector<int>& candidates, int target, int start,
                     vector<int>& ds, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            ds.push_back(candidates[i]);

            combination(candidates, target - candidates[i], i + 1, ds, ans);

            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        combination(candidates, target, 0, ds, ans);

        return ans;
    }
};