#include <bits/stdc++.h>

#define endl '\n'
#define int long long
const int inf = 1e18;

using namespace std;

const long long MOD = 1e9 + 7;

long long powMOD(long long x, long long y)
{
    long long res = 1;
    x = x % MOD;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

void Solve()
{
    int n; cin >> n;
    vector<int> par(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        par[u] = v;
    }

    vector<bool> vis(n + 1, false);
    int cy = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cy++;
            while (!vis[i]) {
                vis[i] = true;
                i = par[i];
            }
        }
    }

    cout << (powMOD(2, cy) - 1) % MOD << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("C:\\Sublime\\input.txt", "r", stdin);
    freopen("C:\\Sublime\\output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
        Solve();

    cerr << "Done!" << endl;

    return 0;
}
