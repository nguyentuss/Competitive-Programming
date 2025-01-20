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
const int MAX_N = 3e5 + 7;
const int MOD = 1e9 + 7;

struct seg {
    int gcd , nn;
};

int n;
seg IT[4*MAX_N];
int a[MAX_N];
map<int , int> cnt;
vector<int> pos[MAX_N];
int b[MAX_N];

inline int _gcd(int a, int b) {
  while (a > 0 && b > 0) {
    if (a > b) a %= b;
    else b %= a;
  }
  return a + b;
}

void build(int id , int l , int r) {
    if (l == r) {
        IT[id].gcd = a[l];
        IT[id].nn = a[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*id , l , mid);
    build(2*id + 1 , mid + 1 , r);
    IT[id].nn = min(IT[2*id].nn , IT[2*id + 1].nn);
    IT[id].gcd = _gcd(IT[2*id].gcd , IT[2*id + 1].gcd);
    return;
}

int getmin(int id , int l , int r , int L , int R) {
    if (l > R || r < L) return inf;
    if (l <= L && R <= r) {
        return IT[id].nn;
    }
    int mid = (L + R)/2;
    return min(getmin(2*id , l , r , L , mid) , getmin(2*id + 1 , l , r , mid + 1 , R));
}

int getgcd(int id , int l , int r , int L , int R) {
    if (l > R || r < L) return 0;
    if (l <= L && R <= r) {
        return IT[id].gcd;
    }
    int mid = (L + R)/2;
    return _gcd(getgcd(2*id , l , r , L , mid) , getgcd(2*id + 1 , l , r , mid + 1 , R));
}

int calc(int x , int l , int r) {
    int pp = 0;
    int left = 0 , right = pos[x].size() - 1;
    while (left <= right) {
        int mid = (left + right)/2;
        if(pos[x][mid] <= r) {
            left = mid + 1;
            pp = mid;
        }
        else {
            right = mid - 1;
        }
    }
    left = 0 , right = pp;
    int pl = 0;
    while (left <= right) {
        int mid = (left + right)/2;
        if (pos[x][mid] >= l) {
            right = mid - 1;
            pl = mid;
        }
        else left = mid + 1;
    }
    return (pp - pl + 1);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        b[i] = a[i];
        //pos[a[i]].push_back(i);
    }    
    sort(b + 1 , b + 1 + n);
    int l = 0;
    for (int i = 1 ; i <= n ;i ++) {
        if (cnt[b[i]] == 0) cnt[b[i]] = ++l;
    }
    for (int i = 1 ; i <= n ; i++) {
        pos[cnt[a[i]]].push_back(i);
    }
    build(1 , 1 , n);
    int m; cin >> m; 
    for (int i = 1 ; i <= m ; i++) {
        int l , r; cin >> l >> r;
        int x = getmin(1 , l , r , 1 , n);
        //cout << getgcd(1 , l , r , 1 , n) << " ";
        if (x == getgcd(1 , l , r , 1 , n)) {
            //cerr << i;
            int num = calc(cnt[x] , l , r);
            cout << (r - l + 1) - num << '\n';
        }
        else cout << r - l + 1 << '\n';
    }
    return 0;
}