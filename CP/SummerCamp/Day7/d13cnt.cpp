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
const int inf = 1e9 + 7;
const int MAX_N = 1e9 + 7;
const int MOD = 1e9 + 7;

int f[32];
set<int , greater<int>> st;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m , k; cin >> n >> m >> k;
    f[0] = 1;
    for (int i = 1 ; i <= n ;i ++) {
        f[i] = f[i - 1] * 2;
        st.insert(f[i]);
    }
    for (int i = 1 ; i <= q ;i ++) {
        int x , y , u , v; cin >> x >> y >> u >> v;
        bitset<50> s;
        s = x;

        cout 
    }
    return 0;
}

// 4 5 7 6 7 5 4 4 6 4