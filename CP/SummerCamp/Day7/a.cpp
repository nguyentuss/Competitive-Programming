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
const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;

int dx[] = {-2 , -2 , -1 , -1 , 1 , 1 , 2 , 2};
int dy[] = {1 , -1 , 2 , -2 , 2 , -2 , 1 , -1};

struct seg {
    int x , y , val;
};
 int n , k;

bool check(int x , int y) {
    return (1 <= x && x <= n && 1 <= y && y <= n);
}

map<pair<int , int> , long long> cnt;
map<pair<int , int> , bool> m;
seg a[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1 ; i <= k ; i++) {
        cin >> a[i].x >> a[i].y >> a[i].val;
        m[ii(a[i].x , a[i].y)] = true;
    }
    for (int i = 1 ; i <= k ; i++) {
        for (int j = 0 ; j < 8 ; j++) {
            int x = a[i].x + dx[j];
            int y = a[i].y + dy[j];
            if (check(x , y)) {
                cnt[ii(x , y)] += a[i].val;
            }
        }
    }
    long long ans = 0;
    for (auto it : cnt) {
        if (!m[ii(it.fi.fi , it.fi.se)])
        ans = max(ans , it.se);
    }
    cout << ans;
    return 0;
}