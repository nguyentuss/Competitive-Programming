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
        s = s + s;
        int n = s.size(); 
        int i = 0;
        int ans = 0;
        while (i < n/2) {
            ans = i ;
            int k = i , j = i + 1; 
            while (j < n && s[j] >= s[k]) {
                if (s[j] == s[k]) k++; 
                if (s[j] > s[k]) k = i;
                j++;
            }
            while (i <= k) i += j - k;
        }
        cout << s.substr(ans , n/2);
    }
    return 0;
}