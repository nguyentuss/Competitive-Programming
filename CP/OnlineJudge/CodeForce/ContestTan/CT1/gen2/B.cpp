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

int n , w;
int a[N] , b[N] , c[N] , cnt[N];

void init() {
    for (int i = 0 ; i < N ; i++) cnt[i] = 0;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("input.inp","r",stdin);
    freopen("B.out","w",stdout);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    if (w == 1) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[j] == b[i]) {
                    cnt[i]++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (c[i] == b[j]) {
                    ans += cnt[j];
                }
            }
        }
        cout << ans;
    }
    else if (w == 2) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[j] == b[i]) {
                    cnt[i]++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (c[i] == b[j]) {
                    ans += cnt[j];
                }
            }
        }
        init();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (b[i] == a[j]) {
                    cnt[i]++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (2*a[i] > c[j] && a[i] != c[j]) {
                    ans += cnt[i];
                }
            }
        }
        init();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (c[i] == a[j]) {
                    cnt[i]++;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (2*c[i] > b[j] && c[i] != b[j]) {
                    ans += cnt[i];
                }
            }
        }
        init();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (c[i] == b[j]) {
                    cnt[i]++;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (2*b[i] > a[j] && b[i] != a[j]) {
                    ans += cnt[i];
                }
            }
        }
        cout << ans;
    }
    else if (w == 3) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int l = upper_bound(a + 1, a + n + 1, abs(b[j] - c[i])) - a;
                int r = lower_bound(a + 1, a + n + 1, b[j] + c[i]) - a;
                if (r > n || (r <= n && a[r] >= b[j] + c[i])) r--;
                if (l > r) continue;
                ans = ans + (r - l + 1);
            }
        }
        cout << ans;
    }
    return 0;
}
