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
const int MAX_N = 2*1e5;
const int MOD = 1e9 + 7;

struct query {
    int l1 , r1 , l2 , r2 , id;
};

int a[MAX_N];
vector <int> IT(4*2*MAX_N , 0);
vector<query> q;
map<int , int> num;
vector<int> L(2*MAX_N , inf);
vector<int> R(2*MAX_N , 0);
set<int> adj[2*MAX_N];
int ans[MAX_N];
int n , m;

void build(int id , int l , int r) {
    if (l == r) {
        IT[id] = L[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*id , l , mid);
    build(2*id + 1 , mid + 1 , r);
    IT[id] = min(IT[2*id] , IT[2*id + 1]);
}

void update(int id , int i , int l , int r , int val) {
    if (i > r || i < l) return;
    if (l == r) {
        IT[id] = val;
        return;
    }
    int mid = (l + r)/2;
    update(2*id , i , l , mid , val);
    update(2*id + 1, i , mid + 1 , r , val);
    IT[id] = min(IT[2*id] , IT[2*id + 1]);
}

int get(int id , int l , int r , int L , int R , int val) {
    if (l > R || L > r || IT[id] > val) return -1;
    //cerr << "DEBUG";
    if (L == R) {
        return L;
    }
    int res = -1;
    int mid = (L + R)/2;
    if (IT[2*id] <= val) { 
        res = get(2*id , l , r , L , mid , val);
    } 
    if (res == -1 && IT[2*id + 1] <= val) {
        res = get(2*id + 1 , l , r , mid + 1 , R , val);
    }
    return res;
}

int calc(int id , int l , int r , int L , int R) {
    if (l > R || L > r) return inf;
    if (l <= L && R <= r) {
        return IT[id];
    } 
    int mid = (L + R)/2;
    return min(calc(2*id , l , r , L , mid) , calc(2*id + 1 , l , r , mid + 1 , R ));
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    set<int> mark;
    set<int , greater<int>> right;
    map<int , int> change;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        mark.insert(a[i]); 
    }    
    for (int i = 1 ; i <= m ; i++) {
        int l1 , r1 , l2 , r2; cin >> l1 >> r1 >> l2 >> r2;
        q.push_back({l1 , r1 , l2 , r2 , i});
        mark.insert(l2);
        mark.insert(r2);
    }
    int cnt = 0;
    for (auto x : mark) {
        num[x] = ++cnt;
        change[cnt] = x;
    }
    for (int i = 1 ; i <= n ;i ++) {
        int x = num[a[i]];
        L[x] = min(L[x] , i);
        R[x] = max(R[x] , i);
    }
    for (int i = 1 ; i <= n + m ; i++) {
        if (L[i] == R[i]) L[i] = inf;
    }
    change[-1] = -1;
    vector<int> pos(2*MAX_N);
    for (int i = 1 ; i <= n ;i ++) {
        int x = num[a[i]];
        pos[R[x]] = x;
        right.insert(R[x]);
    }
    build(1 , 1 , n + m);
    sort(q.begin() , q.end() , [] (query &a , query &b) {
        return a.r1 < b.r1;
    });
    //cout << IT[1];
    for (int i = 0 ; i < q.size() ; i++) {
        //cout << q[i].l1 << " " << q[i].r1 << '\n';
        auto it = right.upper_bound(q[i].r1);
        while (it != right.end()) {
            update(1 , pos[*it] , 1 , n + m , inf);
            right.erase(it);
            it = right.upper_bound(q[i].r1);
        }
        ans[q[i].id] = change[get(1 , num[q[i].l2] , num[q[i].r2] , 1 , n + m, q[i].l1)];
    }
    for (int i = 1 ; i <= m ; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}


