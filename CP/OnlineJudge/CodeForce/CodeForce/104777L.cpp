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
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    cin >> test;
    while (test--) {
        int n , k , x , m; cin >> n >> k >> x >> m;
        vector<int> s(n) , r(n);
        vector<ii> a;
        for (int i = 0 ; i < n ; i++) cin >> s[i]; 
        for (int i = 0 ; i < n ; i++) cin >> r[i];
        for (int i = 0 ; i < n ; i++) a.push_back(ii(r[i] , s[i]));
        sort(a.begin() , a.end() , greater<ii>());
        // for (auto [b , c] : a) {
        //     cerr << c << " ";
        // } 
        // cerr << '\n';
        // for (auto [b , c] : a) {
        //     cerr << b << " ";
        // }
        priority_queue<int> pq;
        vector<int> up(n , inf) , down(n + 1, inf);
        int sum = 0 , mini = inf;
        for (int i = 0 ; i < n ; i++) {
            pq.push(a[i].se); 
            sum += a[i].se;
            while ((int) pq.size() > (x - 1)) {
                sum -= pq.top(); 
                pq.pop();
            }   
            if ((int) pq.size() == (x - 1)) {
                mini = min(mini , sum);
                up[i] = mini;
            }
        }
        while (!pq.empty()) pq.pop();
        sum = 0 , mini = inf;
        for (int i = n - 1 ; i >= 0 ; i--) {
            pq.push(a[i].se); 
            sum += a[i].se; 
            while ((int) pq.size() > (k - x)) {
                sum -= pq.top(); 
                pq.pop();
            }
            if ((int) pq.size() == (k - x)) {
                mini = min(mini , sum); 
                down[i] = mini;
            }
        }
        if (!(k - x)) {
            down = vector<int>(n + 1, 0);
        }
        if (!(x - 1)) {
            up = vector<int>(n + 1 , 0);
        }
        int maxi = 0;
        for (int i = x - 1 ; i < n ; i++) {
            //cerr << i << " " << a[i].fi << " " << up[i - 1] << " " << down[i + 1] << '\n';
            if ((a[i].se + up[max(0ll ,i - 1)] + down[i + 1]) <= m) {
                maxi = a[i].fi;
                break; 
            }
        }
        cout << (maxi == 0 ? -1 : maxi) << '\n';
    }
    return 0;
}