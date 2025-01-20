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

int fw[N];

void add(int pos) {
    for ( ; pos < N ; pos += pos & (-pos)) {
        fw[pos] += 1;
    }
}

int get(int pos) {
    int ans = 0;
    for ( ; pos > 0 ; pos -= pos & (-pos)) {
        ans += fw[pos];
    }
    return ans;
}


main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        vector<int> pos(n + 1);
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        auto calc1 = [&]() -> int {
            int res = 0;
            for (int i = n ; i >= 1 ; i --) {
                int cur = pos[i] - get(pos[i]);
                res = res + abs(i - cur);    
                add(pos[i]);
            }
            return res;
        };
        auto calc2 = [&](vector<int> pos) -> int {
            int res = 0;
            vector<int> b(n + 1);
            b = a;
            for (int i = 1 ; i <= n ; i++) {
                if (i != b[i]) {
                    swap(b[i] , b[pos[i]]);
                    pos[b[pos[i]]] = pos[i];
                    pos[i] = i;
                    res++;
                }
            }
            return res;
        };
        auto calc3 = [&]() -> int {
            int res = 0;
            vector<int> b(n + 1 , 0);
            vector<int> last(n + 1 , inf);
            for (int i = 1; i <= n ; i++) {
                b[i] = lower_bound(last.begin() + 1 , last.begin() + 1 + n , a[i]) - last.begin();
                res = max(res,b[i]);
                last[b[i]] = min(last[b[i]], a[i]);
            }
            return (n - res);
        };
        auto calc4 = [&](vector<int> pos) -> int {
            int res = 0;
            memset(fw , 0 , sizeof(fw));
            for (int i = n ; i >= 1 ; i--) {
                int cur = get(n) - get(pos[i]) - res;
                if (cur != (n - i)) res++;
                add(pos[i]);
                //cerr << res << " " << i << '\n';
            }
            return res;
        };
        cout << calc1() << ' ' << calc2(pos) << ' ' << calc3() << ' ' << calc4(pos);
    }
    return 0;
}