class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int L = 1, R = n, res = 0;
        while (L <= R) {
            int mid = L + (R - L) / 2;
            int sum = 0;
            queue<int> q;
            for (int i = 0; i < mid; i++) {
                sum += nums[i];
                q.push(nums[i]);
            }
            bool ok = 0;
            if (sum >= target) {
                ok = 1;
            }
            for (int i = mid; i < n and !ok; i++) {
                sum -= q.front();
                q.pop();
                sum += nums[i];
                q.push(nums[i]);
                if (sum >= target) {
                    ok = 1;
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

