//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e3 + 7;
const int MOD = 1e9 + 7;

int len(int l , int r) {
    if (l > r) return 0ll;
    return (r - l + 1);
}
vector<vector<int>> f(N, vector<int> (N , inf));
vector<vector<int>> cost(N, vector<int> (N, inf));
vector<vector<int>> trace(N, vector<int> (N , 0));

void VL(int g , int L , int R , int l , int r){
    if (L > R) return;
    int mid = (L + R)/2;
    f[g][mid] = inf;
    for (int i = l ; i <= r ; i++) {
        if ((i + 1) > mid) continue;;
        int new_cost = f[g - 1][i] + cost[i + 1][mid];
        if (f[g][mid] > new_cost) {1234567890909090909
            f[g][mid] = new_cost; 
            trace[g][mid] = i;
        }
    }
    VL(g , L , mid - 1 , l , trace[g][mid]); 
    VL(g , mid + 1 , R , trace[g][mid] , r);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    //cin >> test;
    while (test--) {
        int n , k; cin >> n >> k;
        vector<int> sum(n + 1 , 0); 
        vector<int> a(n + 1 , 0);
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
            //cout << sum[i] << " ";
        }
        auto cal = [&](int l , int r) -> int {
            if (l > r) return 0ll;
            return (sum[r] - sum[l - 1]);
        };
        auto solve = [&](int l , int r , int h) -> int {
            if (l <= h && h <= r && l > 0 && r > 0 && h > 0)
                return (-cal(l , h) + cal(h + 1 , r) + len(l , h)*a[h] - len(h + 1 , r)*a[h]);
            return 0ll;
        };
        for (int r = 1 ; r <= n ; r++) {
            for (int l = 1 ; l <= r; l++) {
                int left = l , right = r;
                while (right - left > 1) {
                    int mid = (left + right) >> 1;
                    if (solve(l , r , mid) > solve(l , r , mid + 1)) {
                        left = mid;
                    }
                    else 
                        right = mid;
                }
                cost[l][r] = solve(l , r , left + 1);
                //cerr << cost[l][r] << " ";
            }
           // cerr << '\n';
        }
        for (int i = 1 ; i <= n ; i++) 
            f[1][i] = cost[1][i];
        for (int g = 2 ; g <= k ; g++) {
            VL(g , 1 , n , 1 , n);
        }
        cout << f[k][n];
    }
    return 0;
}