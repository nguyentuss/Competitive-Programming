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
const int MAX_N = 5e5 + 7;
const int MOD = 1e9 + 7;

struct seg {
    int val , id;
};

int a[MAX_N];
ii b[MAX_N];
vector<seg> IT;

void update(int id , int i , int L , int R , int val , int pos) {
    if (i < L || i > R) return;
    if (L == R) {
        IT[id].val = val;
        IT[id].id = pos;
        return;
    }
    int mid = (L + R)/2;
    update(2 * id , i , L , mid , val , pos);
    update(2 * id + 1 , i , mid + 1 , R , val , pos);
    if (IT[2 * id].val < IT[2 * id + 1].val) {
        IT[id].val = IT[2 * id].val;
        IT[id].id = IT[2 * id].id;
    }
    else {
        IT[id].val = IT[2 * id + 1].val;
        IT[id].id = IT[2 * id + 1].id;
    }
    return;
}

pair<int , int> get(int id , int l , int r , int L , int R) {
    if (r < L || l > R) {
        return ii(inf , 0);
    }
    if (l <= L && R <= r) {
        return ii(IT[id].val , IT[id].id);
    }
    int mid = (L + R)/2;
    auto tmp1 = get(2 * id , l , r , L , mid);
    auto tmp2 = get(2 * id + 1 , l , r , mid + 1,  R);
    if (tmp1.first < tmp2.first) {
        return tmp1;
    }
    else {
        return tmp2;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        IT.assign(4 * n + 7 , {inf , 0});
        vector<int> f(n + 1 , 0);
        vector<int> dp(n + 1 , 0);
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            f[i] = f[i - 1] + a[i];
            //cout << f[i] << " ";
            b[i].fi = f[i];
            b[i].se = i;
        }
        b[n + 1].fi = 0;
        b[n + 1].se = n + 1;
        //cout << '\n';
        sort(b + 1 , b + 2 + n);
        vector<int> pos(n + 2 , 0);
        map<int , int> m;
        map<int , int> op;
        for (int i = 1 ; i <= n + 1 ;i ++) {
            //cout << b[i].fi << " ";
            pos[b[i].se] = i;
            if (!m[b[i].fi]) {
                m[b[i].fi] = i;
                op[b[i].fi] = 0;
            }
            else op[b[i].fi] = 1;
        }
        //cout << '\n';
        update(1 , pos[n + 1] , 1 , n + 1 , 1 , 1);
        for (int i = 1 ; i <= n ; i++) {
            if (a[i] < 0) dp[i] = dp[i - 1] - 1; 
            if (a[i] == 0) dp[i] = dp[i - 1];
            if (a[i] > 0) dp[i] = dp[i - 1] + 1;
            auto x = get(1 , 1 , m[f[i]] - op[f[i]] , 1 , n + 1);   
            if (x.fi != inf) {
                //cout << i << " " << x.se << " " << x.fi << '\n';
                dp[i] = max(dp[i] , i - x.fi + 1);
            }
            update(1 , pos[i] , 1 , n + 1 , -dp[i] + i + 1 , i + 1);
        }
        /*for (int i = 1 ; i <= n ; i++) {
            cout << dp[i] << " ";
        }
        cout << '\n';*/
        cout << dp[n] << '\n';
    }
    return 0;
}