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
const int MAX_N = 3e6 + 7;
const int MAX_V = 3e6 + 7;
const int MOD = 1e9 + 7;

int cnt[MAX_V];
int f[MAX_V] , d[MAX_V];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a(n);
    int max_num = 0;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1 ; i < MAX_N ;i ++) {
        for (int j = i ; j < MAX_N ; j += i) {
            if (i == j/i) {
                d[j] += cnt[i]*(cnt[i] - 1);
            }
            else d[j] += cnt[i]*cnt[j/i];
        }
    }
    for (int i = 1 ; i < MAX_N ; i++) {
        f[i] = f[i - 1] + d[i];
    }
    int m; cin >> m;
    for (int i = 1 ; i <= m ;i ++) {
        int x; cin >> x;
        cout << n*(n - 1) - f[x - 1] << '\n';
    }
    return 0;
}