#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e18 + 7;
const int MAX_N = 1e9 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int c; cin >> c;
    if (c == 1) {
        cout << "NO";
        return 0;
    }
    for (int i = 1 ; i <= 2e8  ;i ++) {
        int sum = i * i + c;
        int x = sqrt(sum);
        if (x*x == sum){ 
            cout << "YES" << '\n';
            cout << i << " " << x << '\n';
            return 0;
        }
    }
    cout<< "NO";
    return 0;
}