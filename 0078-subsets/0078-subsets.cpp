class Solution {
    void find(vector<int>& nums, int i, int n,
              vector<vector<int>>& ans, vector<int>& ds) {

        if (i >= n) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        find(nums, i + 1, n, ans, ds);
        ds.pop_back();
        find(nums, i + 1, n, ans, ds);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;


        find(nums, 0, nums.size(), ans, ds);

        sort(ans.begin(), ans.end());
        return ans;
    }
};