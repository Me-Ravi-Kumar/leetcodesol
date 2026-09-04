class Solution {
    void maxval(vector<int>& nums, vector<int>& mx) {
        mx[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            mx[i] = max(mx[i - 1], nums[i]);
        }
    }

    void minval(vector<int>& nums, vector<int>& mn) {
        int n = nums.size();

        mn[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            mn[i] = min(mn[i + 1], nums[i]);
        }
    }

public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> mn(n);
        vector<int> mx(n);

        maxval(nums, mx);
        minval(nums, mn);

        for (int i = 0; i < n; i++) {
            if (mx[i] - mn[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};