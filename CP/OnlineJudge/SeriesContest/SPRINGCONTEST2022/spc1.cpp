#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2e5 + 7) 
#define int long long
#pragma GCC optimize("Ofast")

struct seg {
    int ask , val;
};

int IT[4*MAX_N];
int n;
vector<int> a;
map<int , vector<int>> m;
map<int , int> point; 

void build(int id , int l , int r) {
    if (l == r) {
        IT[id] = 0;
        return;
    }
    int mid = (l + r)/2;
    build(2*id , l , mid);
    build(2*id + 1 , mid + 1 , r);
    IT[id] = IT[2*id] + IT[2*id + 1];
    return;
}

void update(int id , int l , int r , int i) {
    if (l > i || r < i) return;
    if (l == r) {
        IT[id] = 1;
        return;
    }
    int mid = (l + r)/2;
    update(2*id , l , mid , i);
    update(2*id + 1 , mid + 1, r , i);
    IT[id] = IT[2*id] + IT[2*id + 1];
    return;
}

int get(int id , int l , int r , int L , int R) {
    if (r < L || R < l) return 0;
    if (L <= l && r <= R) {
        return IT[id];
    }
    int mid = (l + r)/2;
    return (get(2*id , l , mid , L , R) + get(2*id + 1 , mid + 1 , r , L , R));
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    freopen("spc1.inp","r",stdin);
    freopen("spc1.out","w",stdout);
    int t; cin >> t;
    while (t--) {
        int q; cin >> q;
        a.clear();
        m.clear();
        point.clear();
        vector<seg> query;
        query.resize(q + 1);  
        a.push_back(0);
        for (int i = 1 ; i <= q ; i++) {
            cin >> query[i].ask >> query[i].val;
            if (query[i].ask == 1) 
                a.push_back(query[i].val);
        }
        sort(a.begin() , a.end());
        n = a.size() - 1;
        for (int i = 1 ; i <= n ; i++) {
            //cout << a[i] << " ";
            m[a[i]].push_back(i);
        }
        //cout << '\n';
        for (int i = 1 ; i <= n ; i++) {
            point[a[i]] = m[a[i]].size() - 1;
        }
        build(1 , 1 , n);
        vector<int> ask;
        for (int i = q ; i >= 1 ; i --) {
            //cerr << query[i].ask << " " << query[i].val << '\n';
            if (query[i].ask == 1) {
                //cerr << m[query[i].val][point[query[i].val]] << '\n';
                update(1 , 1 , n , m[query[i].val][point[query[i].val]]);
                point[query[i].val] --;
            }
            else {
                int l = 1 , r = query[i].val;
                while (true) {
                    if (l > r || r > n) break;
                    int x = get(1 , 1 , n , l , r);
                    if (x == 0) break;
                    l = r + 1;
                    r = r + x;
                }
                ask.push_back(a[r]);    
               // cerr << a[r] << '\n';
                //cout << a[query[i].val + get(1 , 1 , n , 1 , query[i].val)] << '\n';
            }
        }
        reverse(ask.begin() , ask.end());
        for (auto x : ask) cout << x << '\n';
    }

    return 0;
}