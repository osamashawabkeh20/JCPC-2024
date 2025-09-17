#include <bits/stdc++.h>

#define endl '\n'
#define int long long
const int inf = 1e18;

using namespace std;

void Solve()
{
    int a, n; cin >> a >> n;
    if (n % a == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
