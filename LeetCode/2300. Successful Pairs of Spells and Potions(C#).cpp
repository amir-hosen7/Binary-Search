class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort (potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        vector<int> successful_pair;
        for (int i = 0; i < n; i++) {
            long long need = (success - 1) / spells[i] + 1;
            int idx = lower_bound(potions.begin(), potions.end(), need) - potions.begin();
            successful_pair.push_back(m - idx);
        }
        return successful_pair;
    }
};




//C#

public class Solution {
    int Search(int[] a, int need) {
        int L = 0, R = a.Length - 1, idx = a.Length;
        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (a[mid] >= need) {
                idx = mid;
                R = mid - 1;
            }
            else {
                L = mid + 1;
            }
        }
        return idx;
    }

    public int[] SuccessfulPairs(int[] spells, int[] potions, long success) {
        Array.Sort(potions);
        int n = spells.Length, m = potions.Length;
        int[] successfulPair = new int[n];
        for (int i = 0; i < n; i++) {
            long need = (success - 1) / spells[i] + 1;
            if (need <= 100000) {
                int idx = Search(potions, (int)need);
                successfulPair[i] = m - idx;
            }
            else successfulPair[i] = 0;
        }
        return successfulPair;
    }
}

