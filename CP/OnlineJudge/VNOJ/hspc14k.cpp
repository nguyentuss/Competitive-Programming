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
const int MAX_N = 3e3 + 7;
const int MOD = 1e9 + 7;

int BIT[MAX_N][MAX_N];
int BIT1[MAX_N][MAX_N];
int n , m;

bool check(int x , int y) {
    return (1 <= x && 1 <= y && x <= n && y <= m);
}

void update(int x , int y , int val) {
    for ( ; x <= n ; x += x & (-x)) {
        for (; y < m ; y += y & (-y)) {
            BIT[x][y] += val;
        }
    }
}

void update1(int x , int y , int val) {
    for ( ; x <= n ; x += x & (-x)) {
        for (; y < m ; y += y & (-y)) {
            BIT1[x][y] += val;
        }
    }
}

int get(int x , int y) {
    int val = 0;
    for ( ; x > 0 ; x -= x & (-x)) {
        for ( ; y > 0 ; y -= y & (-y)) {
            val += BIT[x][y];
        }
    }
    return val;
}

int get1(int x , int y) {
    int val = 0;
    for ( ; x > 0 ; x -= x & (-x)) {
        for ( ; y > 0 ; y -= y & (-y)) {
            val += BIT1[x][y];
        }
    }
    return val;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 1 ; i <= q ; i++) {
        int ask; cin >> ask;
        if (ask == 1) {
            int a , b , x , y , w; cin >> a >> b >> x >> y >> w;
            int val = (x - a + 1)*(y - b + 1)*w;
            update(x , y , val);
        }
    }
    return 0;
}