#include <bits/stdc++.h>

using namespace std;

void fileIO(void) {
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
}
void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

typedef long long ll;

int n;
vector<int> a, b;

int G[1001][1001];

vector<vector<vector<int>>> dp;
int func(int idx, int rem, int g) {
    if(rem < 0)
        return 1e9;
    if(idx == n) {
        if(g == 1 && rem == 0)
            return 0;
        else
            return 1e9;
    }

    int &ret = dp[idx][rem][g];
    if(~ret)
        return ret;

    int ch1 = func(idx + 1, rem, g);
    int ch2 = func(idx + 1, rem - 1, G[g][a[idx]]) + b[idx];
    return ret = min(ch1, ch2);
}

void build(int idx, int rem, int g) {
    if(rem < 0)
        return;
    if(idx == n) {
        return;
    }
    int ch1 = func(idx + 1, rem, g);
    int ans = func(idx, rem, g);

    if(ans == ch1) {
        build(idx + 1, rem, g);
    }
    else {
        b[idx] = 1e9;
        build(idx + 1, rem - 1, G[g][a[idx]]);
    }
}

void solve(int tc) {
    cin >> n;
    int k; cin >> k;

    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    dp.assign(n, vector<vector<int>>(6, vector<int>(1001, -1)));
    if(k <= 4) {
        cout << (func(0, k, 0)>=1e9?-1:func(0, k, 0)) << "\n";
    }
    else {
        int ans = func(0, 4, 0);

        if(ans >= 1e9)
            return void(cout << -1 << "\n");

        build(0, 4, 0);

        sort(b.begin(), b.end());

        for (int i = 0; i < k - 4; ++i) {
            ans += b[i];
        }

        cout << ans << "\n";
    }

}

signed main() {

    fastIO(); fileIO();
    cout << setprecision(10) << fixed;
    int t = 1; cin >> t;


    vector<int> divs[1001];
    for (int i = 1000; i >= 1; --i) {
        for (int j = i; j <= 1000; j += i) {
            divs[j].push_back(i);
        }
    }

    for (int i = 1; i <= 1000; ++i) {
        G[i][0] = G[0][i] = i;
        for(auto & d : divs[i]) {
            for (int j = d; j <= 1000; j += d) {
                if(!G[i][j])
                    G[i][j] = d;
            }
        }
    }


    for (int i = 1; i <= t; ++i)
        solve(i);

    return 0;
}
