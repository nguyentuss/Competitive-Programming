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
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

struct seg {
    int val , id;
};

int a[MAX_N];
ii b[MAX_N];
int n , d;
seg IT[4 * MAX_N];
int f[MAX_N];
int trace[MAX_N];

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
    if (IT[2 * id].val > IT[2 * id + 1].val) {
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
        return ii(0 , 0);
    }
    if (l <= L && R <= r) {
        return ii(IT[id].val , IT[id].id);
    }
    int mid = (L + R)/2;
    auto tmp1 = get(2 * id , l , r , L , mid);
    auto tmp2 = get(2 * id + 1 , l , r , mid + 1,  R);
    if (tmp1.first > tmp2.first) {
        return tmp1;
    }
    else {
        return tmp2;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> d;
    vector<int> pos(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        b[i].fi = a[i];
        b[i].se = i;
    }
    sort(b + 1 , b + 1 + n);
    for (int i = 1 ; i <= n ; i++) {
        pos[b[i].se] = i;   
        f[i] = 1; 
    }
    for (int i = 1 ; i <= n ; i++) {
        int l = 1 , r = n;
        int p1 , p2;
        p1 = p2 = -1;
        while (l <= r) {
            int mid = (l + r)/2;
            if ((a[i] - b[mid].fi) >= d) {
                l = mid + 1;
                p1 = mid;
            } 
            else r = mid - 1;
        }
        l = 1 , r = n;
        while (l <= r) {
            int mid = (l + r)/2;
            if ((a[i] - b[mid].fi) <= -d) {
                r = mid - 1;
                p2 = mid;
            }
            else l = mid + 1;
        }
        //cout << p1 << " " << p2 << '\n';
        if (p1 != -1) {
            auto tm = get(1 , 1 , p1 , 1 , n);
            if (f[i] < (tm.fi + 1)) {
                f[i] = tm.fi + 1;
                trace[i] = tm.se;
            }
        }
        if (p2 != -1) {
            auto tm =  get(1 , p2 , n , 1 , n);
            if (f[i] < (tm.fi + 1)) {
                f[i] = tm.fi + 1;
                trace[i] = tm.se;
            }
        }
        update(1 , pos[i] , 1 , n , f[i] , i);
    }
    int ans = 0 , vt = 0;
    for (int i = 1 ; i <= n ;i ++) {
        if (ans < f[i]) {
            ans = f[i];
            vt = i;
        }   
    }
    // for (int i = 1 ; i <= n ; i++) {
    //     cout << trace[i] << " ";
    // }
    // cout << '\n';
    cout << ans << '\n';
    vector<int> tr;
    tr.push_back(vt);
    while (trace[vt] != 0) {
        vt = trace[vt]; 
        tr.push_back(vt);
    }
    reverse(tr.begin() , tr.end());
    //for (auto x : tr) cout << x << " ";
    return 0;
}

// |h[i] - h[j]| >= d
// h[i] - h[j] >= d
// h[i] - h[j] <= -d;
// -(h[i] - h[j]) >= d
// h[j] - h[i] >= d

// 3 - 5 >= -5
// -2 >= -5



