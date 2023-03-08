class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int L = 0, R = 10000000, res = 0;
        while (L <= R) {
            int mid = L + (R - L) / 2, ok = 0;
            long long tot = 0;
            for (int i = 0; i < n and mid; i++) {
                tot += (candies[i] / mid);
                if (tot >= k) {
                    ok = 1; break;
                }
            }
            if (ok) {
                res = mid;
                L = mid + 1;
            }
            else {
                R = mid - 1;
            }
        }
        return res;
    }
};
