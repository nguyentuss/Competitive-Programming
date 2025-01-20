    //#pragma GCC optimize("Ofast")
    //#pragma GCC target("avx,avx2,fma,popcnt")
    #include <bits/stdc++.h>
    using namespace std;

    #define int long long
    #define rep(i, a, b) for(int i = a; i < (b); ++i)
    #define all(x) begin(x), end(x)
    #define sz(x) (int)(x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
    const int inf = 1e9; 

    const int N = 2e5 + 7;

    int a[N];

    void solve() {
        int n,m,k;
        cin >> n >> m >> k;
        int q; cin >> q;
        for(int i = 1 ;i <= q ; i++) cin >> a[i];
        vector<int> v;
        for(int i = 1 ; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int num = min(min(n-i+1,i),min(n-k+1,k))*min(min(m-j+1,j),min(m-k+1,k));
                v.push_back(num);
            }
        }
        sort(a + 1,a + q + 1);
        sort(v.begin(),v.end());
        reverse(a + 1 , a + 1 + q);
        reverse(v.begin() , v.end());
        int ans = 0;
        for(int i = 0; i< q; i++){
            ans += v[i]*a[i + 1];
        }
        cout << ans << '\n';
    }

    signed main() {
        ios::sync_with_stdio(0); cin.tie(0);
        cin.exceptions(cin.failbit);
        int test; 
        test = 1;
        cin >> test;
        while (test--) {
            solve();
        }

    }