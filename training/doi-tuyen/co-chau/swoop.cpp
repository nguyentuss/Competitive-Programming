#include<bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e5 + 7)

int x[MAX_N] , y[MAX_N];

signed main() {
    freopen("swoop.inp","r",stdin);
    freopen("swoop.ans","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    double ans = 0.0;
    for (int i = 1 ; i <= n ; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1 ; i < n ; i++) {
        double x1 = x[i] , x2 = x[i + 1] , y1 = y[i] , y2 = y[i + 1];        
        ans = max(ans , hypot(abs(x1 - x2) , abs(y1 - y2)));
    }
    cout << fixed << setprecision(6) << ans;

    return 0;
}


// voi i : (x[i] - x[j])^2 + (y[i] - y[j])^2
// x[i]^2 - 2*x[i]*x[j] + x[j]^2 + y[i]^2 - 2*y[i]*y[j] + y[j]^2
// x[i]^2 + y[i]^2 + x[j]^2 + y[j]^2 - 2*x[i]*x[j] - 2*y[i]*y[j] 
    