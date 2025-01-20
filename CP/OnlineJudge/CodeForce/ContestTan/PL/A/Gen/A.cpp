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

char a[N];
int l_1[N] , l_2[N] , r_1[N] , r_2[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("input.inp","r",stdin);
    freopen("A.out","w",stdout);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    // xet doan dai nhat cua >
    int l = 1;
    int xx = 0;
    a[n + 1] = (a[n] == '<' ? '>' : '<');
    for (int i = 1 ; i <= n + 1 ; i++) {
        if (a[i] == '<') {
            l_1[l] = xx;
            r_1[i - 1] = xx;
            l = i + 1;
            xx = 0;
        }
        else {
            xx++;
        }
    }
    // xet doan dai nhat cua <
    xx = 0;
    for (int i = 1 ; i <= n + 1 ; i++) {
        if (a[i] == '>') {
            l_2[l] = xx;
            r_2[i - 1] = xx;
            l = i + 1;
            xx = 0;
        }
        else {
            xx++;
        }
    }
    int ans = 0;
    int status = 0;
    // status = 0 la chua bat dau
    // status = 1 la dag xet toi <
    // status = 2 la dag xet toi >
    int cnt = 0;
    a[n + 1] = a[n];
    a[0] = a[1];
    for (int i = 0 ; i <= n ; i++) {
        if (status == 0) {
            if (a[i] == '>') status = 1;
            else status = 2;
            cnt++;
        }
        else {
            if (a[i] != a[i + 1]) {
                if (status == 1) {
                    ans += cnt;
                    status = 2;
                    cnt = 1;
                }
                else {
                    ans = ans + max(r_2[i] , l_1[i + 1]);
                    status = 1;
                    cnt = 0;
                }
            }
            else {
                ans += cnt;
                cnt++;
            }
        }
        //cout << ans << " ";
    }
    cout << ans;
    return 0;
}
