#include <bits/stdc++.h>

#define endl '\n'
#define int long long
const int inf = 1e18;

using namespace std;

void Solve()
{
    int n, q;
    cin >> n >> q;

    vector<char> gay(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> gay[i];
    }

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i >= 3) {
            pre[i] = pre[i - 3];

            pre[i] += min(abs(gay[i] - 'z'), 26 - abs(gay[i] - 'z'));
            pre[i] += min(abs(gay[i - 1] - 'o'), 26 - abs(gay[i - 1] - 'o'));
            pre[i] += min(abs(gay[i - 2] - 'd'), 26 - abs(gay[i - 2] - 'd'));
        }
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        if (r - l + 1 < 3) {
            cout << -1 << endl;
        }

        else {
            int plus = (r - l + 1) % 3;

            int ans = INT_MAX;
            if (plus == 0) {
                ans = pre[r] - pre[l - 1];
            }

            else if (plus == 1) {
                ans = min(pre[r] - pre[l], pre[r - 1] - pre[l - 1]);
            }

            else {
                ans = min({ pre[r] - pre[l + 1], pre[r - 1] - pre[l], pre[r - 2] - pre[l - 1] });
            }

            cout << ans << endl;
        }
    }
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
