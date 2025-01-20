#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

#define int long long

int f[N];
int a[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int sum1 = 0 , sum2 = 0;
        for (int i = 1 ; i <= n ; i++) cin >> a[i];
        for (int i = 1 ; i <= n ; i+=2) {
            if (a[i] > 0) {
                sum1 += a[i];
            }
        }
        for (int i = 2 ; i <= n ; i+=2) {
            if (a[i] > 0) {
                sum2 += a[i];
            }
        }
        int cnt1 = 0 , cnt2 = 0;
        int dem1 = 0 , dem2 = 0;
        int max1 = LLONG_MIN , max2 = LLONG_MIN;
        for (int i = 1 ; i <= n ; i+=2) {
            if (a[i] < 0) cnt1++;
            dem1++;
            max1 = max(max1 , a[i]);
        }
        for (int i = 2 ; i <= n ; i+=2) {
            if (a[i] < 0) cnt2++;
            dem2++;
            max2 = max(max2 , a[i]);
        }
        if (cnt1 == dem1) sum1 = max1;
        if (cnt2 == dem2) sum2 = max2; 
        cout << max(sum1 , sum2) << '\n';
    }
    return 0;
}