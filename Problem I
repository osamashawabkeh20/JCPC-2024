#include <bits/stdc++.h>
#define GO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
#define pb push_back
#define all(a) a.begin(), a.end()
constexpr int mod = (int)(1e9 + 7);

constexpr int N = 6e5 + 7;

basic_string<int> adj[N];
int deg[N], dp[N];

int main() {
    GO
    int K; cin>>K;
    deg[1] = 6;
    dp[1] = 1;
    for(int i = 2 ; i <= 7 ; i++){
      adj[i].pb(1);
      dp[i] = 11;
    }
    int len = 1;
    for(int st = 8, jmp = 12 ; ; st += jmp, jmp += 6){
      int last = st - jmp + 6;
      int h = 0;
      for(int i = st ; i < st + jmp ; i++){
        adj[i].pb(last);
        deg[last]++;
        if(h){
          last++;
          if(last == st) last = st - jmp + 6;
          adj[i].pb(last);
          deg[last]++;
        }
        h++;
        if(h == len + 1) h = 0;
      }
      int sum = 0;
      for(int j = st - jmp + 6 ; j < st ; j++){
        sum += 1LL * dp[j] * deg[j] % mod * 2 % mod;
        if(sum >= mod) sum -= mod;
      }
      for(int i = st ; i < st + jmp ; i++){
        dp[i] = sum;
        for(int x : adj[i]){
          dp[i] += mod - dp[x];
          if(dp[i] >= mod) dp[i] -= mod;
        }
      }
      if(last >= K) break;
      len++;
    }
    cout<<dp[K]<<'\n';






    return 0;
}

