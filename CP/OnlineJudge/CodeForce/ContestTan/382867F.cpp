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
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;
int ro[] = {3 , 0 , 0 , 1};
iv q[MAX_N];
int a[MAX_N];
int prevL = 0 , prevR = 0;
deque<int> dq[MAX_N];
int IT[4*MAX_N];
int ans[MAX_N];
int n;
int pow2[MAX_N];
int f[MAX_N];
int BLOCK;

void build(int id , int l , int r) {
    if (l == r) {
        f[l] = id;
        return;
    }
    int mid = (l + r)/2;
    build(2*id , l , mid);
    build(2*id + 1, mid + 1 , r); 
}

void init() {
    pow2[0] = 1;
    for (int i = 1 ; i <= 50 ; i++) {
        pow2[i] = pow2[i - 1]*2;
    }
}
bool cmp(iv &a , iv &b) {
	return ((a.se.fi/BLOCK < b.se.fi/BLOCK) || (a.se.fi/BLOCK == b.se.fi/BLOCK && a.se.se/BLOCK < b.se.se/BLOCK));
}

int hilbert(int x , int y , int pow , int rotate) {
    if (pow == 0) return 0;
    int npow = pow2[pow - 1];
    int seg = ((x < npow) ? ((y < npow) ? 0 : 3) : ((y < npow) ? 1 : 2));
    seg = (seg + rotate)&3;
    int nro = (ro[seg] + rotate)&3;
    int nx = x & (x ^ npow) , ny = y & (y ^ npow);
    int cnt = pow2[2 * pow - 2];
    int ans = cnt * seg;
    int add = hilbert(nx , ny , pow - 1 , nro);
    ans += (seg == 1 || seg == 2) ? add : (cnt - add - 1);
    return ans;
}

void update(int id , int val) {
    IT[id] = val;
    while (id > 1) {
        id /= 2;
        IT[id] = max(IT[2*id] , IT[2*id + 1]);
    }
}

int get(int x) {
    if (!dq[x].size()) return 0ll;
    else return (dq[x].back() - dq[x].front());
}

void MO(int i) {
    int L = q[i].se.fi , R = q[i].se.se;
    while (L < prevL) {
        prevL--;
        dq[a[prevL]].push_front(prevL);
        update(f[a[prevL]] , get(a[prevL]));
    }
    while (prevR < R) {
        prevR++; 
        dq[a[prevR]].push_back(prevR);
        update(f[a[prevR]] , get(a[prevR]));
    }
    while (L > prevL) {
        if (!dq[a[prevL]].empty())
        dq[a[prevL]].pop_front();
        update(f[a[prevL]] , get(a[prevL]));
        prevL++;
    }
    while (prevR > R) {
        if (!dq[a[prevR]].empty())
        dq[a[prevR]].pop_back();
        update(f[a[prevR]] , get(a[prevR]));
        prevR--;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    init();
    build(1 , 1 , n);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    int m; cin >> m;
    for (int i = 1 ; i <= m ; i++) {
        cin >> q[i].se.fi >> q[i].se.se;
        q[i].fi.se = i;
        q[i].fi.fi = hilbert(q[i].se.fi , q[i].se.se , 18 , 0);
    }
    sort(q + 1 , q + 1 + m );
    for (int i = 1 ; i <= m ; i++) {
        MO(i);      
        ans[q[i].fi.se] = IT[1];
    }
    for (int i = 1 ; i <= m ; i++) {
         cout << ans[i] << '\n';
    }
    return 0;
}