#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

int n;
ii a[N];
int X[N];
int res = inf;

void write() {
    int ans = 0;
    set<int , greater<int>> s;
    for (int i = 1 ; i <= n ; i ++) {
        if (X[i] == 1) {
            s.insert(a[i].fi);
            ans += a[i].se;
        }
    }
    for (int i = 1 ; i <= n ;i ++) {
        auto it = s.lower_bound(a[i].fi);
        if (it == s.end()) {
            return;
        }
        ans = ans + a[i].fi - *it;
    }
    res = min(res , ans);
}

void backtr(int i) {
    for (int j = 0 ; j <= 1 ; j++) {
        X[i] = j;
        if (i == (n + 1)) {
            write();
        }
        else backtr(i + 1);
    }

}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("input.inp","r",stdin);
    freopen("B.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1 , a + 1 + n);
    backtr(1);
    cout << res;
    return 0;
}
