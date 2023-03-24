//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/horse-race-122f4ccc/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

//Horse Race

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, x;
        cin >> n >> m >> x;
        vector<ll> v(n);
        unordered_map<ll, ll> cnt;
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
            cnt[v[i]]++;
        }
        ll l = 0, r = n, res = 0;
        while (l <= r) {
            ll mid = l + (r - l) / 2, ok = 1, tot = 0, sum = 0;
            for (ll i = 1; i <= m; i++) {
                sum += cnt[i];
                if (cnt[i] > mid) {
                    tot += (cnt[i] - mid);
                }
            }
            ll optrn = min(x, (n - sum) + tot);
            for (ll i = 1; i <= m; i++) {
                if (cnt[i] < mid) {
                    ll dif = mid - cnt[i];
                    if (dif <= optrn) {
                        optrn -= dif;
                    }
                    else {
                        ok = 0; break;
                    }
                }
            }
            if (ok) {
                res = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        cout << res << "\n";
    }
    return 0;
}


