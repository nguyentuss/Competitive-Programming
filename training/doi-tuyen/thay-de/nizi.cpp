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
const int MAX_N = 1e6 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("nizi.inp","r",stdin);
    freopen("nizi.out","w",stdout);
    int n; cin >> n;
    deque<int> dq;
    for (int i = 1 ; i <= n ; i++) {
        int x; cin >> x;
        dq.push_back(x);
    }   
    int ans = 0;
    bool ch = 0;
    while (!dq.empty()) {
        int d1 = 0 , d2 = 0;
        bool found = false;
        d1 = dq.front();
        dq.pop_front();
        if (!dq.empty()) d2 = dq.back() , dq.pop_back() , found = true;
        if (!found) break;
        if (d1 != d2) {
            while (true) {
                while (d1 < d2) {
                    int x = 0;
                    if (dq.empty()) break;
                    if (!dq.empty()) {
                        x = dq.front();
                        dq.pop_front();
                        d1 += x;
                        ans++;
                    }
                }
                while (d1 > d2) {
                    int x = 0;
                    if (dq.empty()) break;
                    if (!dq.empty()) {
                        x = dq.back(); 
                        dq.pop_back();
                        d2 += x;
                        ans++;
                    }
                }
                //cerr << ans << " " << d1 << " " << d2 << '\n';
                if (dq.empty() && d1 != d2) {
                    //cerr << "EE";
                    ch = true;
                    ans++;
                    break;
                }
                if (d1 == d2) break;
            }
            if (ch) break;
        }
    }
    cout << ans;
    return 0;
}