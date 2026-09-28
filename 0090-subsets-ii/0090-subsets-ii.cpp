class Solution {
    void find(vector<int>& nums, int i, int n, vector<vector<int>>& ans,
              vector<int>& ds) {

        ans.push_back(ds);

        for (int j = i; j < n; j++) {

            if (j > i && nums[j] == nums[j - 1])
                continue;

            ds.push_back(nums[j]);

            find(nums, j + 1, n, ans, ds);

            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        find(nums, 0, nums.size(), ans, ds);

        return ans;
    }
};