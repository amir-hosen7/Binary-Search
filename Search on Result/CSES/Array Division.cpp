#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define Mid(b, e) b + (e - b) / 2
#define inf 1e18
double PI = 2 * acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[] = {1, 2, 2, 1, -1, -2, -2, -1};

//8 direction
// ll dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// ll dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

//4 direction
// ll dx[]={1, -1, 0, 0};
// ll dy[]={0, 0, 1, -1};

void yesNo(bool ck){cout << (ck ? "YES\n" : "NO\n");}
//------------------------------------------------------------------------------//

//ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
//string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const ll P = 29;
const ll N = 2e5 + 50;
const ll mod = 1e9 + 7;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll t = 1;
    for (ll T = 1; T <= t; T++) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        ll Max = 0, sum = 0;
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
            Max = max(Max, v[i]);
            sum += v[i];
        }
        ll l = Max, r = sum, res;
        while (l <= r) {
            ll mid = l + (r - l) / 2, curr_sum = 0, cnt = 1;
            for (ll i = 0; i < n; i++) {
                if ((curr_sum + v[i]) <= mid) {
                    curr_sum += v[i];
                }
                else {
                    cnt++;
                    curr_sum = v[i];
                }
            }
            if (cnt <= k) {
                r = mid - 1;
                res = mid;
            }
            else {
                l = mid + 1;
            }
        }
        cout << res << "\n";
    }
    return 0;
}





