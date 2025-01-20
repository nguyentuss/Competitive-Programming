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
        string s; cin >> s;
        string t; cin >> t;
        int n = s.size();
        int m = t.size();
        auto prefix_function = [&](string t) -> vector<int> {
            vector<int> pi(n);
            for (int i = 1 ; i < m ; i++) {
                int j = pi[i - 1];
                while (j > 0 && t[i] != t[j]) {
                    j = pi[j - 1];
                }
                if (t[i] == t[j]) {
                    j ++;
                }
                pi[i] = j;
            }
            return pi; 
        };
        vector<int> pi = prefix_function(t);
        int ans = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j > 0 && s[i] != t[j])
                j = pi[j - 1];
            if (t[j] == s[i])
                j++;
            if (j == m) {
                ans++; 
                cout << (i + 1) - m + 1 << " ";
            }
        }

        //cout << ans;
    }
    return 0;
}
