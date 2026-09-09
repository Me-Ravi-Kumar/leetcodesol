class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1000; // 10^3
        long long commas = 1;

        while (start <= n) {
            long long end;
            if (start > n / 1000) {
                end = n;
            } else {
                end = start * 1000 - 1;
                end = min(end, n);
            }
            long long count = end - start + 1;

            ans += count * commas;

            if (start > n / 1000)
                break;

            start *= 1000;
            commas++;
        }
        return ans;
    }
};