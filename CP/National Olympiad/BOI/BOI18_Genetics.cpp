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
const int MAX_N = 4107;
const int MOD = 1e9 + 7;

bitset<4101> a[MAX_N];
bitset<4101> c;
int b[MAX_N][MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m , k; cin >> n >> m >> k;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            char x; cin >> x;
            if (x == 'A') {
                a[i][j] = 1;
            }
            else {
                a[i][j] = 0; 
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < i ; j++) {
            c = a[i] ^ a[j];
            int cnt = c.count();
            if (cnt == k) b[i][j] = b[j][i] = 1;
            else b[i][j] = b[j][i] = 0;
        }
    }
    
    for (int i = 0 ; i < n ; i++) {
        int cnt = 0;
        for (int j = 0 ; j < n ; j++) {
            cnt = cnt + (b[i][j] ? 1 : 0);
            //cout << b[i][j] << " ";
        }
        if (cnt == (n - 1)) {
            cout << i + 1;
            return 0;
        }
        //cout << '\n';
    }
    return 0;
}