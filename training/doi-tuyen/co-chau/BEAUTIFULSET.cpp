#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7) 
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    int n , p; cin >> n >> p;
    vector<int> a(n + 1);
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
        a[i] %= p;
    }
    sort(a.begin() + 1 , a.begin() + 1 + n);

    return 0;
