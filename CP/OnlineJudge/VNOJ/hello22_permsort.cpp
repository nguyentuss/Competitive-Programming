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

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , k; cin >> n >> k;
    vector<int> p(n) , q(n + 1) , IT(4*n + 1 , 1) , cost(n + 1 , 1);
    for (int i = 0 ; i < n ; i++) {
        cin >> p[i];
        q[p[i]] = i;
    }
    function <void(int , int , int , int , int)> update = [&](int id , int l , int r , int pos , int x) {
        if (l > pos || r < pos) return;
        if (l == r) {
            IT[id] = x; 
            return;
        }
        int mid = (l + r) / 2;
        update(2*id , l , mid , pos , x);
        update(2*id + 1, mid + 1 , r , pos , x);
        IT[id] = min(IT[2*id] , IT[2*id + 1]);
    };
    function <int(int , int , int , int)> find = [&](int id , int l , int r , int x) {
        if (IT[id] > x) return -1LL;
        if (l == r) {
            return l;
        }
        int mid = (l + r)/2;
        if (IT[2*id] <= x) return find(2*id , l , mid , x);
        else return find(2*id + 1 , mid + 1 , r , x);
    };

    for (int pos = 0 ; pos < n ; pos++) {
        int val = find(1 , 1 , n , k - cost[p[pos]]);
        //cerr << val << " ";
        if (val != -1 && p[pos] > val) {
            int nxt_pos = q[val];
            swap(p[pos] , p[nxt_pos]);
            swap(q[p[pos]] , q[p[nxt_pos]]);
            cost[p[nxt_pos]] += cost[p[pos]];
            update(1 , 1 , n , p[nxt_pos] , cost[p[nxt_pos]]);
        }
        cost[p[pos]] = inf;
        update(1 , 1, n , p[pos] , cost[p[pos]]);
    }
    for (int i = 0 ; i < n ; i++) cout << p[i] << " ";
    return 0;
}

    







