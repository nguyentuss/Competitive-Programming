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
const int MAX_N = 1e5 + 7 ;
const int MOD = 1e9 + 7;

int P[MAX_N][20];

int get(int a , int b) {
    int k = log2(b - a + 1);
    return max(P[a][k] , P[b - (1 << k) + 1][k]);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m; cin >> n >> m;
    vector<int> v;
    map<int , int> cnt;
    for (int i = 1 ; i <= n ; i++) {
        int x; cin >> x;
        v.push_back(x);
        cnt[x]++;
    }
    if (cnt.size() == 1) {
        cout << 0;
        return 0;
    }
    sort(v.begin() , v.end());
    if (m > n) {
        priority_queue<int> pq;
        for (int i = 0 ; i < (v.size() - 1) ; i++) {
            pq.push(v[i + 1] - v[i]);
        }
        int last = m - n;
        while (last --) {
            int x = pq.top();
            pq.pop();
            if (x % 2 == 0) {
                pq.push(x / 2);
                pq.push(x / 2);
            }
            else {
                pq.push(x/2);
                pq.push(x - (x/2));
            }
        }
        cout << pq.top();
    }
    else {
        for (int i = 1 ; i < n ; i++) {
            P[i][0] = v[i] - v[i - 1];
        }
        for (int j = 1 ; (1 << j) < n ; j++) {
            for (int i = 1 ; (i + (1 << j) - 1) < n ; i++) {
                P[i][j] = max(P[i][j - 1] , P[i + (1 << (j - 1))][j - 1]);
            }
        }
        int ans = inf; 
        for (int i = 0 ; i <= (n - m) ; i++) {
            ans = min(ans , get(i + 1 , i + m - 1));
        }
        cout << ans;
    }

    return 0;
}