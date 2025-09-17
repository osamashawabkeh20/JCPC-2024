#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(s) (int)(s).size()
#define all(s) s.begin(),s.end()

void Speed() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    int n; cin >> n;
    vector<vector<array<int, 2>>> adj(n);
    for(int i = 1; i < n; i++){
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> cnt(n);
    vector<ll> sub(n);

    auto dfs = [&](auto& self, int u, int p) -> ll{
        vector<tuple<int, int, ll>> masks;
        cnt[u] = 1;
        ll sum = 0;
        for(auto& [v, w] : adj[u]){
            if(v == p) continue;
            ll down = self(self, v, u);
            cnt[u] += cnt[v];
            sub[u] += sub[v] + 2 * w;
            masks.push_back({v, w, down});
        }
        int m = sz(masks);
        vector<ll> dp(1<<m, -1);
        auto rec = [&](auto& self_rec, int mask, ll cost) -> ll{
            if(mask == 0) return 0;
            auto& ret = dp[mask];
            if(~ret) return ret;
            ret = LLONG_MAX;
            for(int i = 0; i < m; i++){
                if((mask >> i) & 1){
                    auto [v, w, down] = masks[i];
                    ll add = (1ll * cnt[v] * (cost + w)) + down;
                    ret = min(ret, self_rec(self_rec, mask ^ (1<<i),  cost + w * 2 + sub[v]) + add);
                }
            }
            return ret;
        };
        return rec(rec, (1<<m) - 1, 0);
    };

    ll ans = dfs(dfs, 0, -1);
    cout << fixed << setprecision(10) << (long double) 1.0 * ans / n << '\n';
}

int main() {
    Speed();
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
