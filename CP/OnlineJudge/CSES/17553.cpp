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
        int m = s.size();
        int n = t.size(); 
        auto prefix_function = [&](string s) -> vector<int> {
            vector<int> pi(n);
            for (int i = 1 ; i < n ; i++) {
                int j = pi[i - 1]; 
                while (j > 0 && s[i] != s[j]) {
                    j = pi[j - 1];
                }
                if (s[i] == s[j]) j ++; 
                pi[i] = j;
            }
            return pi;
        };
        vector<int> pi = prefix_function(t); 
        int ans = 0 , j = 0;
        for (int i = 0 ; i < m ; i++) {
            while (j > 0 && s[i] != t[j]) {
                j = pi[j - 1]; 
            }
            if (s[i] == t[j]) j++;
            if (j == n) ans++;
        }
        cout << ans;
    }
    return 0;
}