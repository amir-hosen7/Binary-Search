public class Solution {
    public int ShipWithinDays(int[] weights, int days) {
        int l = 0, r = 1000000000, res = 0, n = weights.Length;
        while (l <= r) {
            int mid = l + (r - l) / 2, curr = 0, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (weights[i] > mid) {
                    cnt = 1000000000; break;
                }
                if ((curr + weights[i]) <= mid) {
                    curr += weights[i];
                }
                else {
                    cnt++;
                    curr = 0;
                    i--;
                }
            }
            if (curr != 0) cnt++;
            if (cnt <= days) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }
}

