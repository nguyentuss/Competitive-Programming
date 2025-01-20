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
    int t = 1;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> pi(n); 
        int ans = 0;
        for (int i = 1 ; i < n ; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }    
            if (s[i] == s[j]) j++;
            pi[i] = j;
            if (pi[i] > 0) {
                if (s[0] == s[pi[i] - 1]) {
                    ans += i;
                }
                else {
                    ans = ans + (i + 1) - j;
                }
            }
            //cerr << ans << " ";
        }
        int res = 0;
        // for (int i = 1 ; i < n ;i ++) {
        //     cout << pi[i] << " ";
        // }
        // cout << '\n';
        vector<int> f(n);
        for (int i = 1 ; i < n ; i++) {
            if (pi[i]) {
                f[pi[i]] = f[pi[pi[i] - 1]];
                if (!f[pi[i]]) {
                    f[pi[i]] = pi[i];
                }
            }
        }
        for (int i = 1 ; i < n ; i++) {
            int tm = f[pi[i]];
            if (tm > 0) res = res + (i + 1) - tm; 
            //cerr << tm << " ";
        }
        cout << res;
    }
    return 0;
}