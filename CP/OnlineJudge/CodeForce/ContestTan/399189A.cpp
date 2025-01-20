    #include <bits/stdc++.h>

    using namespace std;

    #define ii pair<int , int>  
    #define iv pair<ii , ii>
    #define iii pair<int , ii>
    #define fi first
    #define se second
    #define int long long

    const int inf = 1e18 + 7;
    const int N = 1e5 + 7;
    const int MOD = 1e9 + 7;

    main() {
        ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
        int n , k; cin >> n >> k;
        multiset<int , greater<int>> s;
        for (int i = 1 ; i <= n ;i ++) {
            int x; cin >> x;
            s.insert(x);
        }
        int ans = 0;
        while (s.size()) {  
            int x = *s.begin();
            ans += x;
            s.erase(s.begin());
            while (true) {
                auto it = s.lower_bound(x - k);
                if (it == s.end()) break;
                x = *it;
                s.erase(it);
            }
        }
        cout << ans;
        return 0;
    }