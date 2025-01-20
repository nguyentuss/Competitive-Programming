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
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

int a[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
    int mex = 1;
    for (int i = 1 ; i <= n && a[i] <= mex ;i++) {
        mex += a[i];
    }
    cout << mex;
    return 0;
}


