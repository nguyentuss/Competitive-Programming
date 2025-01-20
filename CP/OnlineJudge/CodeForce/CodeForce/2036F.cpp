#include <bits/stdc++.h>

#define int long long

using namespace std;

int xorcum(int n) {
    int mod = n % 4;
    if (mod == 0)
        return n;
    else if (mod == 1)
        return 1;
    else if (mod == 2)
        return n + 1;
    else
        return 0;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r, i, k;
        cin >> l >> r >> i >> k;
        int res = xorcum(l - 1) ^ xorcum(r);
        
        int mu = 1LL << i;

        int x = (l - k + mu - 1) / mu;
        if (l - k < 0)
            x = 0;
            
        int y = (r - k) / mu;
        if (r - k < 0)
            y = -1;
            
        if (x > y) {
            cout << res << "\n";
            continue;
        }
        
        int m = xorcum(y) ^ xorcum(x - 1);
        
        res ^= (m << i);
        
        if ((y - x + 1) % 2 == 1) {
            res ^= k;
        }
        cout << res << "\n";
    }
}