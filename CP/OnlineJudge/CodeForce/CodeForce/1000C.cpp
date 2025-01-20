#include <bits/stdc++.h>

#pragma GCC targer("avx2")
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
map<int , int> m , cnt;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ;i ++) {
        int x , y; cin >> x >> y;
        m[x] ++;
        m[y + 1] --;   
    }
    auto it = m.begin();
    int x = it->second , l = it->first;
    it++;
    while (it != m.end()) {
        int dist = it->first - l;
        cnt[x] += dist;
        l = it->first;
        x += it->second; 
        it++;
    }
    for (int i = 1 ; i <= n ; i++) cout << cnt[i] << " ";
    return 0;
}
