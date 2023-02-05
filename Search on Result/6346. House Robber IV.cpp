class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int L = 0, R = 1e9, res = 0;
        while (L <= R) {
            int mid = L + (R - L) / 2, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) {
                    cnt++, i++;
                }
            }
            if (cnt >= k) {
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
