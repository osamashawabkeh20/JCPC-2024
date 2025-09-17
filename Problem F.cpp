#include <bits/stdc++.h>

#define endl '\n'
#define int long long
const int inf = 1e18;

using namespace std;

void Solve()
{
    int a, b, x; cin >> a >> b >> x;
    if ((a & b) >= x)
        return void (cout << 0 << endl);

    vector<int> bitA(32), bitB(32);
    set<int> dif;
    int ctr = 0;
    int sum = (a & b);

    while (a or b) {
        if (a % 2 == 1) {
            bitA[ctr] = 1;
        }
        if (b % 2 == 1) {
            bitB[ctr] = 1;
        }

        if (a % 2 != b % 2) {
            dif.insert(ctr);
        }
        ctr++;
        a >>= 1ll;
        b >>= 1ll;
    }

    vector<pair<int, int>> ans;

    for (int i = 30; i >= 0; i--) {
        if (bitA[i] == 1 and bitB[i] == 1) {
            continue;
        }

        int lastDif = 0;
        if (dif.size() == 0)
            lastDif = 0;
        else
            lastDif = (1ll << * (dif.rbegin()));
        if (dif.size() == 0) {
            ans.push_back({0, i});
            ans.push_back({1, i});
            sum += (1ll << i);
            if (sum >= x)
                break;
            continue;
        }
        if (sum + lastDif >= x) {
            if (bitA[*dif.rbegin()] == 0) {
                ans.push_back({0, *dif.rbegin()});
            }
            else {
                ans.push_back({1, *dif.rbegin()});
            }
            break;
        }

        if (*dif.rbegin() == i) {
            sum += lastDif;
            if (bitA[*dif.rbegin()] == 0) {
                ans.push_back({0, *dif.rbegin()});
            }
            else {
                ans.push_back({1, *dif.rbegin()});
            }
            dif.extract(*dif.rbegin());
        }
        else {
            ans.push_back({0, i});
            ans.push_back({1, i});
            sum += (1ll << i);
            if (sum >= x)
                break;
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << char(ans[i].first + 'a') << " " << ans[i].second << endl;
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
