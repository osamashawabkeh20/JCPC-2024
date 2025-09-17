#include <bits/stdc++.h>

#define endl '\n'
#define int long long
const int inf = 1e18;

using namespace std;

void Solve()
{
    const int N = 2e6 + 7;
    vector<bool> pr(N + 5, true);
    pr[0] = pr[1] = false;
    for (int i = 2; i <= N; i++) {
        if (pr[i]) {
            for (int j = i + i; j <= N; j += i) {
                pr[j] = false;
            }
        }
    }

    int n; cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (pr[x]) continue;
        if (x % 2 == 0) ans++;
        else {
            if (pr[x - 2]) ans++;
            else ans += 2;
        }
    }
    cout << ans << endl;
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
    // cin >> t;
    while (t--)
        Solve();

    cerr << "Done!" << endl;

    return 0;
}
