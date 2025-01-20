#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (5e5 + 7)
#define ll long long

int n , v[MAX_N];
int sum[MAX_N] , revsum[MAX_N];
unordered_map<int , int> cnt;

void init() {
    for (int i = 0 ; i < MAX_N; i++) {
      sum[i] = 0;
      revsum[i] = 0;
      v[i] = 0;
    }
    cnt.clear();
    return;
}       
            
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cout.tie(NULL);
  //freopen("wc6.inp","r",stdin);
  //freopen("wc6.out","w",stdout);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    init();
    sum[0] = revsum[n + 1] = 0;
    for (int i = 1 ; i <= n; i ++)  
        cin >> v[i];
    int tmp = n + 1;            
    for (int i = 1 ; i <= n; i++) {
        sum[i] = sum[i - 1] + v[i];
        revsum[tmp - i] = revsum[tmp - i + 1] + v[tmp - i];        
    }                              
    for (int i = 1 ; i <= n - 1 ; i ++) 
        cnt[revsum[i]] ++;
    ll res = 0LL;
    for (int i = 1 ; i <= n - 2 ; i++) {
        cnt[revsum[i]] --;
        if (2*sum[i] == revsum[i + 1]) {
            res += cnt[sum[i]];
        }
    }
    cout << res << '\n';
  }
  return 0;
}