#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL); 
    int t; cin >> t;
    while (t--) {
        int n , m; cin >> n >> m;
        string s;
        int cnt = 0;
        string s1 = "" , s2 = "";
        int status = 0;
        s1 += "1";
        for (int i = 2 ; i <= m ; i++) {
            cnt++;
            if (!status) {
                s1 += '0';
            } 
            else s1 += '1';
            if (cnt % 2 == 0) {
                status ^= 1;
            }  
        }
        for (int i = 0 ; i < s1.size() ;i ++) {
            if (s1[i] == '1') s2 += '0';
            else s2 += '1';
        }
        string c1 = "" , c2 = "";
        for (int i = 0 ; i < s1.size() ; i++) {
            c1 += s1[i];
            c1 += " ";
            c2 += s2[i];
            c2 += " ";
        }
        cnt = 0;
        cout << c1 << '\n';
        status = 0;
        for (int i = 2 ; i < n ; i++) {
            cnt++;
            if (!status) cout << c2 << '\n';
            else cout << c1 << '\n';
            if (cnt % 2 == 0) status ^= 1;
        }
        if (status) cout << c1 << '\n';
        else cout << c2 << '\n';
    }
    return 0;
} 
/*

1 0 0 1 0 0 1 0
0 1 0 0 1 1 0 1
1 0 1 1 0 0 1 0 
0 1 0 0 1 1 0 1 
1 0 1 1 0 0 1 0 
0 1 0 1 0 1 0 1 

0
1 0
*/