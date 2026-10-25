#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    freopen("xaule.inp","r",stdin);
    freopen("xaule.out","w",stdout);
    int n , b; cin >> n >> b;
    vector<int> a(n + 1) , v(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        if (a[i] == b) v[i] = 0;
        else if (a[i] > b) v[i] = 1;
        else v[i] = -1;
    }
    vector<int> f(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        f[i] = f[i - 1] + v[i];
        //cerr << f[i] << " ";
    }
    //cerr << '\n';
    map<int , int> even , odd;
    odd[0] = 1;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (i % 2 == 0) {
            ans += even[f[i]];
            odd[f[i]]++;
        }
        else {
            ans += odd[f[i]];
            even[f[i]]++;
        }
      //  cerr << ans << " " << i << '\n';
    }
    cout << ans;
    

    return 0;
}