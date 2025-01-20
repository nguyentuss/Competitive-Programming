#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5e2 + 7)
#define MAX_VAL (int) (50007)
#define inf (int) (1e9 + 7)
#define int long long

int f[MAX_N][MAX_VAL];
int n , W;
int a[MAX_N] , b[MAX_N] , t[MAX_N];

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cout.tie(NULL);
  freopen("test.inp","r",stdin);
  cin >> n >> W;
  int value = 0;
  for (int i = 1 ; i <= n ; i++) {
    cin >> a[i] >> b[i] >> t[i];
    value += t[i];
  }
  for (int i = 0 ; i <= n ; i++) {
    for (int j = 0 ; j <= value; j++) {
      f[i][j] = inf;
    }
  }
  f[0][0] = 0;
  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j <= value ; j++) {
      if (f[i][j] == inf) continue;
      if (j + t[i + 1] <= value)
        f[i + 1][j + t[i + 1]] = min(f[i + 1][j + t[i + 1]] , f[i][j] + b[i + 1]);
      f[i + 1][j] = min(f[i + 1][j] , f[i][j] + a[i + 1]);
    }
  }
  for (int i = 0 ; i <= value ; i++) {
    if (f[n][i] <= W) {
    	cout << i;
    	return 0;
    }
  }
  cout << -1;
  return 0;
}