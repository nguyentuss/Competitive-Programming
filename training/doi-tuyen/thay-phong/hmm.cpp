#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    freopen("hmm.inp","r",stdin);
    freopen("hmm.out","w",stdout);
    int a; cin >> a;
    cout << a*6 + ((a*(a - 1))/2)*6 + 1;
    return 0;
}