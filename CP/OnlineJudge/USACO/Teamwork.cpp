#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {    
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , k; cin >> n >> k;
    vector<int> a(n + 1 , 0);
    for (int i = 1; i <= n ; i++) {
        cin >> a[i];
    }
    vector<int> f;
    f.resize(n + 1 , 0);
    for (int i = 1 ; i <= n ; i++) {
        int maxi = 0 , len = 0;
        for (int j = i ; j >= max(1ll , i - k + 1) ; j--) {
            maxi = max(maxi , a[j]);
            len++;
            f[i] = max(f[i] , f[j - 1] + maxi*len);
            //if (i == 4) cerr << f[i] << " ";
        } 
    }
    cout << f[n];
    return 0;
}