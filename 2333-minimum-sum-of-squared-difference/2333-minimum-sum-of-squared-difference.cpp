
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,int k2) {
        int n = nums1.size();
        long long op = (long long)k1 + k2;

        vector<int> diff(n);
        int maxDiff = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i];
        }

        if (op >= total)
            return 0;

        vector<int> freq(maxDiff + 1, 0);

        for (int d : diff) {
            freq[d]++;
        }

        for (int d = maxDiff; d > 0 && op > 0; d--) {
            int take = min((long long)freq[d], op);

            freq[d] -= take;
            freq[d - 1] += take;
            op -= take;
        }

        long long ans = 0;

        for (int d = 0; d <= maxDiff; d++) {
            ans += 1LL * d * d * freq[d];
        }

        return ans;
    }
};
