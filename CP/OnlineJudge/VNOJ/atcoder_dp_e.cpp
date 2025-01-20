#include <bits/stdc++.h>

using namespace std;

#define MAX_N (ll) (1e2 + 7)
#define MAX_VAL (ll) (1e6 + 7)
#define inf (ll) (1e9 + 7)
#define ll long long

ll f[MAX_N][MAX_VAL];
ll n , W;
ll val[MAX_N] , weight[MAX_N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> W;
  ll value = 0;
  for (ll i = 1 ; i <= n ; i++) {
    cin >> weight[i] >> val[i];
    value += val[i];
  }
  for (ll i = 0 ; i <= n ; i++) {
    for (ll j = 1 ; j <= value; j++) {
      f[i][j] = inf;
    }
  }
  for (ll i = 0 ; i < n ; i++) {
    for (ll j = 0 ; j <= value ; j++) {
      if (f[i][j] == inf) continue;
      if (j + val[i + 1] <= value)
        f[i + 1][j + val[i + 1]] = min(f[i + 1][j + val[i + 1]] , 
      f[i][j] + weight[i + 1]);
      f[i + 1][j] = min(f[i + 1][j] , f[i][j]);
    }
  }
  ll ans = 0;
  for (ll i = 0 ; i <= value ; i++) {
    if (f[n][i] <= W) ans = i;
  }
  cout << ans;
  return 0;
}