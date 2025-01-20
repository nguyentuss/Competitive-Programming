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
//#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;

int n;
int a[MAX_N];
int IT[4 * MAX_N];
int bit[MAX_N];

void update(int id , int i , int l , int r , int val) {
    if (i > r || i < l) return;
    if (l == r) {
        IT[id] += val;
        return;
    }
    int mid = (l + r)/2;
    update(2 * id , i , l , mid , val);
    update(2 * id + 1 , i , mid + 1 , r , val);
    IT[id] = IT[2 * id] + IT[2 * id + 1];
    return;
}

int get(int id , int L , int R , int l , int r) {
    if (R < l || r < L) return 0;
    if (L <= l && r <= R) return IT[id];
    int mid = (l + r)/2;
    return (get(2*id , L , R , l , mid) + get(2*id + 1 , L , R , mid + 1, r));
}

void up(int i , int val) {
    int idx = i;
    while (idx <= n) {
        bit[idx] += val;
        idx += (idx & (-idx));
    }
}

int g(int u) {
    int idx = u , ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    unordered_map<int , int> cnt;
    for (int i = n ; i >= 1 ; i--) {
        cnt[a[i]]++;
        int x = cnt[a[i]];
        //update(1 , x , 1 , n , 1);
        up(x , 1);
    }

    unordered_map<int , int> cnt1;
    long long ans = 0;
    for (int i = 1 ; i < n ; i++) {
        cnt[a[i]]--;
        cnt1[a[i]] ++;
        int x = cnt[a[i]]; 
        //update(1 , x + 1 , 1 , n , -1);
        up(x + 1 , -1);
        //ans += get(1 , 1 , cnt1[a[i]] - 1, 1 , n);
        ans += g(cnt1[a[i]] - 1);
    }
    cout << ans;
    return 0;
}