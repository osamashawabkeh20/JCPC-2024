// Mtaylor
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define endl '\n';
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
typedef long long ll;
const int N = 3e5 + 5;

int n, k;
ll a[N];
ll b[N];
ll pref[2][N];
ll val[N];
ll val2[N];
void test_case() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    stack<pair<ll, ll> > st;
    multiset<ll> s;
    for (int i = 1; i < k; i++) {
        pref[0][i] = pref[0][i - 1] + (b[i] - a[i]);
        pref[1][i] = pref[1][i - 1] + b[i];
    }
    ll ans = -1e18;
    for (int i = k; i <= n; i++) {
        pref[0][i] = pref[0][i - 1] + (b[i] - a[i]);
        pref[1][i] = pref[1][i - 1] + b[i];
        int l = i - k;
        ll r = pref[1][i] - pref[1][l];
        val2[l] = pref[0][l];
        while (st.size() && st.top().se < r) {
            int idx = st.top().fi;
            st.pop();
            s.erase(s.find(val[idx]));
            val2[l] = min(val2[l], val2[idx]);
        }
        val[l] = val2[l] + r;
        st.push({l, r});
        s.insert(val[l]);
        if (s.size()) {
            ans = max(ans, pref[0][i] - (*s.begin()));
        }
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        test_case();
    }
    return 0;
}
