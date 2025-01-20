#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

int a[N];
int b[N];
int n;
int ans = inf;

int f(int mid) {
    int sum_1 = 0 , sum_2 = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (b[i] < mid) {
            sum_1 += a[i]*(mid - b[i]);
        }
        else sum_2 += a[i]*(b[i] - mid);
    }
    //cout << mid << " " << sum_1 + sum_2 << " ";
    return (sum_1 + sum_2);
}

void solve() {
    int l = 1 , r = 1e9;
    int K = 100;
    for (int i = 0 ; i < K ; i++) {
        int x1 = l + (r - l)/3;
        int x2 = r - (r - l)/3;
        if (f(x1) >= f(x2)) {
            if (x1+1 > r) break;
            l = x1+1;
        }
        else {
            if (x2 - 1 < l) break;
            r = x2 - 1;
        }
        //cout << l << " " << x1 << " " << x2 << " " << r;
        //cout << '\n';
    }
    cout << f(l);

}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    for (int i = 1 ; i <= n ; i++) cin >> b[i];
    solve();
    return 0;
}
