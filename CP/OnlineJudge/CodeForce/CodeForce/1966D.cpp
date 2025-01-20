    //source:: 
    #include <bits/stdc++.h>

    using namespace std;

    #define int long long

    const int inf = 1e18 + 7;
    const int N = 2e5 + 7;
    const int MOD = 1e18 + 7;

    int cnt = 0;

    void solve() {
        cnt++;
        int n , k; cin >> n >> k;
        // if (n == 10000 && cnt == 56) {
        //     cout << n << '|' << k << '|';
        //     return;
        // }
        vector<int> a;
        int pw2 = 1; 
        int sum = 1;
        while (true) {
            if (pw2 <= k && k <= (pw2*2 - 1)) {
                if (pw2 - (pw2 * 2 - k) > 0) a.push_back(pw2 - (pw2 * 2 - k)); 
                a.push_back(k + 1);
                bool status = false;
                int cc = 1;
                for (int i = 1 ; i <= 25 ; i++) {
                    cc *= 2; 
                    if (cc - 1 == k) {
                        a.push_back(cc + 1);
                        status = true;
                        break;
                    }
                }
                if (!status) a.push_back(sum);
            }
            else a.push_back(pw2);
            pw2 *= 2ll;
            sum += pw2;
            if (pw2 > n) {
                break;
            }
        }
        cout << a.size() << '\n';
        for (int x : a) cout << x << " ";
        cout << '\n';
    }

    main() {
        ios_base::sync_with_stdio(0); cin.tie(NULL); 
        cout.tie(NULL);
        int test = 1;
        cin >> test;
        while(test--) {
            solve();
        }
        return 0;
    }