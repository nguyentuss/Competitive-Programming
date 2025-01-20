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

int aut[N][26];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; t = 1;
    while (t--) {
        string s; cin >> s;
        string t; cin >> t;
        int n = s.size();
        int m = t.size();
        vector<vector<int>> f(n + 1 , vector<int> (m + 1, -inf));
        auto KMP = [&](string s) -> vector<int> {
            int j = 0;
            vector<int> pi(s.size());
            for (int i = 1 ; i < (int) s.size() ; i++) {
                j = pi[i - 1];
                while (j > 0 && s[i] != s[j]) {
                    j = pi[j - 1];
                }
                if (s[i] == s[j]) j++;
                pi[i] = j;
            }
            return pi;
        };
        vector<int> pi = KMP(t); 
        auto KMP_automaton = [&]() -> void {
            for(int i = 0 ; i < m ; i++) {
                for (int c = 0 ; c < 26 ; c++) {
                    if (t[i] - 'a' == c) {
                        aut[i][c] = i + 1; 
                    }
                    else {
                        if (i > 0)
                            aut[i][c] = aut[pi[i - 1]][c];
                    }
                }
            }
        };
        KMP_automaton();
        f[0][0] = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (f[i][j] == -inf) continue;
                for (int c = 0 ; c < 26 ; c++) {
                    int cs = 0;
                    int nj;
                    if (s[i] == '?' || (s[i] - 'a' == c)) {
                        int nj = aut[j][c];
                        if (nj == m) {
                            cs = 1;
                            nj = pi[m - 1];
                        }
                        f[i + 1][nj] = max(f[i + 1][nj] , f[i][j] + cs);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0 ; i < m ; i++) {
            ans = max(ans , f[n][i]);
        }
        cout << ans;
    }
    return 0;
}