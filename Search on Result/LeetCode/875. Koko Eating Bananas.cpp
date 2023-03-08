class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int L = 1, R = 1000000000, res;
        while (L <= R) {
            int mid = L + (R - L) / 2, ok = 1, tot = 0;
            for (int i = 0; i < n; i++) {
                tot += (piles[i] - 1) / mid + 1;
                if (tot > h) {
                    ok = 0; break;
                }
            }
            if (ok) {
                res = mid;
                R = mid - 1;
            }
            else {
                L = mid + 1;
            }
        }
        return res;
    }
};

