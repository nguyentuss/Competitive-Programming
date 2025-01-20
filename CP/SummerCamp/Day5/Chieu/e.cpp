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
const int MAX_N = ;
const int MOD = 1e9 + 7;

struct seg {
    int x , t , y , r;
};

bool cmp(seg &a , seg &b) {
    return a.x < b.x;
}

seg a[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , s1 , s2; cin >> n >> s1 >> s2;

    for (int i = 1 ; i <= n ; ++) {
        cin >> a[i].x >> a[i].t >> a[i].y >> a[i].r;
    }
    sort(a + 1 , a + 1 + n);
    vector<vector<vector<int>>> f(2 , vector<vector<int>> (s1 + 1, vector<int>(s2 + 1))));
    f[0][0][0] = 0;
    for (int i = 1 ; i <= n ; i++)) {
        int now = i & 1;
        int prev = now ^ 1;
        f[prev].assign(vector<vector<int>>(vector<int>(inf)));
        for (int w1 = s1 ; w1 >= 0 ; w1--) {
            for (int w2 = s2 ; s2 >= 0 ; s2--) {
                if (w1 < s1) {
                    f[now][w1 + ()]
                } 
            }
        }
    }
    return 0;
}