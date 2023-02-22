public class Solution {
    public int SingleNonDuplicate(int[] nums) {
        int n = nums.Length;
        int L = 0, R = n - 1, res = 0;
        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (mid != (n - 1) && nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 1) {
                    R = mid - 1;
                }
                else {
                    L = mid + 1;
                }
            }
            else if (mid != 0 && nums[mid] == nums[mid - 1]) {
                if ((mid - 1) % 2 == 1) {
                    R = mid - 1;
                }
                else {
                    L = mid + 1;
                }
            }
            else {
                res = nums[mid]; break;
            }
        }
        return res;
    }
}
