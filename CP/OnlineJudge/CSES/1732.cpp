#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        vector<int> pi(n + 1);
        for (int i = 1 ; i < n ; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
        vector<int> ans;
        int j = pi[n - 1];
        while (j > 0) {
            ans.push_back(j);
            j = pi[j - 1];
        }
        reverse(ans.begin() , ans.end());
        for (auto x : ans) {
            cout << x << " "; 
        }
    }
    return 0;
}