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
const int inf = 1e18 + 7;
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

struct seg {
    int x , y , id;
};

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("kill.inp","r",stdin);
    freopen("kill.out","w",stdout);
    int n , k; cin >> n >> k;
    vector<seg> v;
    vector<int> a;
    vector<int> b;
    for (int i = 1 ; i <= n ;i ++) {
        int x; cin >> x;
        a.push_back(x);
    }
    for (int i = 1 ; i <= n ;i ++) {
        int x; cin >> x;
        b.push_back(x);
    }
    for (int i = 0 ; i < a.size() ; i++) {
        v.push_back({a[i] , b[i] , i});
    }
    sort(v.begin() , v.end() , [](seg a ,seg b) {
        return a.x < b.x;
    });
    priority_queue<int> q;
    vector<int> ans(n + 1);
    for (int i = 0 ; i < v.size() ; i++) {
        vector<int> tmp;
        int cnt = 0;
        int total = v[i].y;
        while (!q.empty()) {
            int x = q.top();
            q.pop();
            cnt++;
            total += x;
            tmp.push_back(x);
            if (cnt == k) break;
        }
        ans[v[i].id] = total;
        for (auto x : tmp) {
            //cerr << x << " ";
            q.push(x);
        }
        q.push(v[i].y);
        //cerr << '\n';
    }
    for (int i = 0 ; i < n ; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}