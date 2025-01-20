#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e6 + 7;
const int MAX_ELE = 1e6 + 7;
const int MAX_N = 3*1e5 + 7;
const int MOD = 1e9 + 7;

int a[MAX_N];
int D[MAX_ELE];
int IT[4*MAX_N];

void build(int id , int l , int r) {
    if (l == r) {
        IT[id] = a[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*id , l , mid);
    build(2*id + 1 , mid + 1 , r);
    IT[id] = IT[2*id] + IT[2*id + 1];
    return;
}

void update(int id , int i , int L , int R , int val) {
    if (i > R || i < L) return;
    if (L == R) {
        IT[id] = val;
        return;
    }
    int mid = (L + R)/2;
    update(2*id , i , L , mid , val);
    update(2*id + 1 , i , mid + 1 , R , val);
    IT[id] = IT[2*id] + IT[2*id + 1];
}

int get(int id , int l , int r , int L , int R) {
    if (l > R || r < L) return 0;
    if (l <= L && R <= r) {
        return IT[id];
    }
    int mid = (L + R)/2;
    return (get(2*id , l , r , L , mid) + get(2*id + 1 , l , r , mid + 1 , R));
}

void sieve() {
    for (int i = 1 ; i < MAX_ELE ; i++) {
        D[i] ++;
        for (int j = 2*i ; j < MAX_ELE ; j += i) {
            D[j]++;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    sieve();
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    build(1 , 1 , n);
    set<int> s;
    for (int i = 1 ; i <= n ; i++) if (a[i] != 1 || a[i] != 2) s.insert(i);
    //cerr << "DEBUG";
    for (int i = 1 ; i <= m ; i++) {
        int ask , l , r; cin >> ask >> l >> r;
        if (ask == 1) {
            auto it = s.lower_bound(l);
            while (*it <= r) {
                update(1 , *it , 1 , n , D[a[*it]]);
                a[*it] = D[a[*it]];
                auto x = it;
                it++;
                if (a[*x] == 1 || a[*x] == 2)
                    s.erase(x);
            }
            //  for (auto x : s) cout << x << " ";
            //      cout << '\n';
        }
        else {
            cout << get(1 , l , r , 1 , n) << '\n';
        }
    }
    return 0;
}