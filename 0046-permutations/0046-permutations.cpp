class Solution {
    void permutation(vector<int>& nums, int n, int i, vector<vector<int>>& result, vector<int>& ds,vector<int>& visited) {
        if (i == n) {
            result.push_back(ds);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                visited[j] = 1;
                ds.push_back(nums[j]);
                permutation(nums, n, i + 1, result, ds, visited);
                ds.pop_back();
                visited[j] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> ds;
        vector<int> visited(n, 0);
        permutation(nums, n, 0, result, ds, visited);
        return result;
    }
};