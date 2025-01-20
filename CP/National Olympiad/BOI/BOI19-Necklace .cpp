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
        string s , t; cin >> s >> t;
        int n = s.size();
        int m = t.size(); 
        auto KMP = [&](string s) -> vector<int> {
            vector<int> pi(n);
            for (int i = 1 ; i < s.size() ; i++) {
                int j = pi[i - 1];
                while (j > 0 && s[i] != s[j]) {
                    j = pi[j - 1]; 
                }
                if (s[i] == s[j]) {
                    j ++;
                }
                pi[i] = j;
            }
            return pi;
        };
        /*zxyabcd -> cdab
          yxbadctz*/
          
        int ans = 0;
        for (int i = 0 ; i < n ; i++) {
            string s1 = s.substr(0 , i) , s2 = s.substr(i , n - i);
            reverse(s1.begin() , s1.end());
            string t1 = t , t2 = t;
            reverse(t2.begin() , t2.end()); 
            vector<int> pi1 = KMP(s1 + "#" + t1); 
            vector<int> pi2 = KMP(s2 + "#" + t2);
            for (int j = 1 ; j <= m ; j++) {
                ans = max(ans , {pi1[i + j] + });
            }
        }
    }
    return 0;
}