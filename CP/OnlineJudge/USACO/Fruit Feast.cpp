#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int t , a , b; cin >> t >> a >> b;
    vector<bool> f(2*t + 1 , 0);
    vector<bool> g(2*t )
    f[0] = true;
    for (int i = 1 ; i <= 2*t ; i++) {
        if ((i - a) >= 0 && f[i - a]) {
            f[i] = true;
        }
        if ((i - b) >= 0 && f[i - b]) {
            f[i] = true;
        }
    }
    int ans = 0;
    for (int i = 0 ; i <= t ; i++) {
        if (f[i] || f[2*i]) {
            ans = i;
        }
    }
    cout << ans;
    return 0;
}