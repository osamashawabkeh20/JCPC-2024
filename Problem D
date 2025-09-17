#include <bits/stdc++.h>

#define endl '\n'
#define int long long
const int inf = 1e18;

using namespace std;

int calc(int n) {
    int ans = 0;
    for (int i = 5; i <= n; i *= 5) {
        ans += (n + 1) * (n / i) - i * ((n / i) * (n / i + 1) / 2);
    }
    return ans;
}

void Solve()
{
    int l, r; cin >> l >> r;
    cout << calc(r) - calc(l - 1) << endl;
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
