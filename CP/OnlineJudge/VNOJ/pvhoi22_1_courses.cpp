#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (2e3 + 7)
#define inf (int) (1e18)
#define MAX_M (int) (3e5 + 7)
#define ii pair<int , int>
#pragma GCC optimize("Ofast")

struct seg {
    int val , lazy;
};
seg IT[4*MAX_N];
int n , m , len;
int e[MAX_N];
int s[MAX_M];
int f[MAX_N];
ii neg[MAX_N];;
int sum[MAX_N];
int p[MAX_N];

void down(int id) {
    int x = IT[id].lazy;
    IT[2*id].val += x;
    IT[2*id].lazy += x;
    IT[2*id + 1].val += x;
    IT[2*id + 1].lazy += x;
    IT[id].lazy = 0;
}

void update(int id , int l , int r , int L , int R , int x) {
    if (l > R || r < L) return;
    if (L <= l && r <= R) {
        IT[id].val += x;
        IT[id].lazy += x;
        return;
    }
    down(id);
    int mid = (l + r)/2;
    update(2*id , l , mid , L , R , x);
    update(2*id + 1 , mid + 1 , r , L , R , x);
    IT[id].val = min(IT[2*id].val , IT[2*id + 1].val);
    return;
}

int get(int id , int l , int r , int L , int R) {
    if (l > R || r < L) return inf;
    if (L <= l && r <= R) {
        return IT[id].val;
    }
    down(id);   
    int mid = (l + r)/2;
    return min(get(2*id , l , mid , L , R) , get(2*id + 1 , mid + 1 , r , L , R));
}

void build(int id , int l , int r) {
    if (l == r) {
        IT[id].val = sum[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*id , l , mid);
    build(2*id + 1 , mid + 1 , r);
    IT[id].val = min(IT[2*id].val , IT[2*id + 1].val);
}

signed main() {    
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int positive = 0;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> e[i];
        if (e[i] < 0) {
            neg[++len].first = e[i];
            neg[len].second = i;
        }
        else {
            positive ++;
        }
    }
    for (int i = 1 ; i <= m ; i++) cin >> s[i];
    sort(neg + 1 , neg + 1 + len);
    reverse(neg + 1 , neg + 1 + len);
     for (int i = 1 ; i <= m ;i++) {
        sum[0] = s[i];
        for (int h = 1 ; h <= n ; h++) {
           sum[h] = sum[h - 1] + max(0ll , e[h]);
        }
        for (int h = 1 ; h < 4*n ; h++) {
            IT[h].lazy = 0;
        }
        build(1 , 1 , n);
        int l = 1 , cnt = 0;
        for (int j = 1 ; j <= len ; j++) {
            int pos = neg[j].second;
            if (neg[j].first + get(1 , 1 , n , pos , pos) >= 0) {
               // cout << neg[j].first << " " << neg[j].second << '\n';
                update(1 , 1 , n , pos , n , neg[j].first);
                if (get(1 , 1 , n , pos , n) < 0) {
                    cnt--;
                    update(1 , 1 , n , pos , n , -neg[j].first);
                }
                cnt++;
            }
            l = pos + 1;
        }
        printf("%lld " , positive + cnt);
    }
    return 0;
}