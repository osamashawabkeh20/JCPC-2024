#include <bits/stdc++.h>

#define endl '\n'
#define int long long
const int inf = 1e18;

using namespace std;

void Solve()
{
    int n; cin >> n;
    vector<pair<int, int>> a{{0, 0}};
    map<int, int> quick;
    set<int> s;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        a.push_back({x, y});
        quick[x] = i;
        s.insert(x);
    }

    vector<int> suf(n + 3);

    for (int i = n - 1; i; --i) {
        suf[i] = suf[i + 1] + max(llabs(a[i].first - a[i + 1].first), llabs(a[i].second - a[i + 1].second));

    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        auto bs = s.upper_bound(x);
        if (bs == s.end()) {
            cout << (int)1e9 + 1 - x << endl;
            continue;
        }
        int sum = max(llabs(x - a[quick[*bs]].first), llabs(y - a[quick[*bs]].second));
        sum += suf[quick[*bs]];
        sum += llabs(1e9 + 1 - a.back().first);
        cout << sum << endl;
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
    cin >> t;
    while (t--)
        Solve();

    cerr << "Done!" << endl;

    return 0;
}
