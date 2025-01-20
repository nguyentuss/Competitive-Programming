//source:: https://codeforces.com/gym/104777/problem/I
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
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

int solve(int x1 , int y1 , int x2 , int y2) {
    return (abs(x1 - x2) + abs(y1 - y2));
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int> a;
        for (int i = 0 ; i < 2*n ; i++) {
            int x;cin >> x; 
            a.push_back(x);
        }
        sort(a.begin(), a.end()); 
        vector<ii> points;
        for (int i = 0 ; i < n ; i++) {
            points.push_back(ii(a[i] , a[2*n - 1 - i]));
        }
        int ans = 0; 
        for (int i = 0 ; i < n - 1 ; i++) {
            ans += solve(points[i].fi , points[i].se , points[i + 1].fi , points[i + 1].se);
        }
        cout << ans << '\n';
        for (int i = 0 ; i < n ; i++) {
            cout << points[i].fi << " " << points[i].se << '\n';
        }
    }
    return 0;
}