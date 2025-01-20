#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n , k; cin >> n >> k;
        unordered_map<int , int> pos;
        set<int , greater<int>> s;
        for (int i = 1 ; i <= n ; i++) {
            int x; cin >> x;
            pos[x] = i;
            s.insert(x);
        }
        int l = 1 , r = 1e15; 
        int mini;
        while (l <= r) {
            int mid = (l + r)/2;
            int sm = mid;
            bool ok = true;
            for (int d = 1 ; d <= k ; d++) {
                auto it = s.lower_bound(sm);
                if (it == s.end()) break;
                sm -= pos[*it];
            }
            if (sm >= 1) {
                mini = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << mini << '\n';
    }
    return 0;
}