//source:: 
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int MOD = 1e18 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a;
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin() , a.end()); 
    vector<pair<int , int>> b; 
    int prev = a[0];
    int cnt = 0;
    a.push_back(0);
    for (int x : a) {
        if (x != prev) {
            b.push_back(pair<int , int>(prev , cnt));
            cnt = 1;
        }
        else {
            cnt++;
        }
        prev = x;
    }

    for (auto x : b) {
        cout << x.first << " ";
    }
    cout << '\n';
    for (auto x : b) {
        cout << x.second << " ";
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    cout.tie(NULL);
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}