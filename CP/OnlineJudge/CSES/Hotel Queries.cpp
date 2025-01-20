#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

int n , m; 
int a[MAX_N] , IT[4*MAX_N];

void build(int id , int l , int r) {
    if (l == r) {
        IT[id] = a[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*id , l , mid);
    build(2*id + 1 , mid + 1 , r);
    IT[id] = max(IT[2*id] , IT[2*id + 1]);
}

void update(int id , int l , int r , int i , int x) {
    if (l > i || r < i) return;
    if (l == r) {
        IT[id] -= x;
        return;
    }
    int mid = (l + r)/2;
    update(2*id , l , mid , i , x);
    update(2*id + 1 , mid + 1 , r , i , x);
    IT[id] = max(IT[2*id] , IT[2*id + 1]);
}

int query(int id , int l , int r , int x) {
    if (l == r) {
        //IT[id] -= x;
        return l;
    } 
    int mid = (l + r)/2;
    if (IT[2*id] >= x) {
        query(2*id , l , mid , x);
    }
    else query(2*id + 1 , mid + 1 , r , x);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    build(1 , 1 , n);
    for (int i = 1 ; i <= m ; i++) {
        int x; cin >> x;
        //cerr << "DEBUG";
        if (IT[1] < x) cout << "0 ";
        else {
            int pos = query(1 , 1 , n , x);
            cout << pos << " ";
            update(1 , 1 , n , pos , x);
        }
    }
    return 0;
}