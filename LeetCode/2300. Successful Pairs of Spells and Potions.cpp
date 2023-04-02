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

