#include <bits/stdc++.h>

using namespace std;

#define int long long

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , t; cin >> n >> t;
    vector<int> a(n);
    int maxi = 0;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        maxi = max(maxi , a[i]);
    }

    auto check = [&] (int times) {
        int tmp = 0;
        for (int i = 0 ; i < n ;i ++) {
            tmp += times/a[i];
            if (tmp >= t) return true;
        }
        return (tmp >= t);
    };

    int l = 0 , r = maxi*t;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}