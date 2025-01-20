#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 3e5 + 7;
const int MOD = 1e9 + 7;

int d[N][27];
int a[N];
int dp[N][27];
int l[27];
int cnt[27];
int ans[27];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    map<int,int> mp;
    for (int i = 1 ; i <= n ; i++) {
        a[i] = (int) (s[i] - 'a');
        mp[a[i]]++;
        dp[i][1] = 1;
        for (int j = 0 ; j < 26 ; j++) {
            d[i][j] = d[i - 1][j] + (a[i] == j ? 1 : 0);
        }
    }
    for (int i = 0 ; i < 26 ; i++) l[i] = 1;
    cout << mp.size() << '\n';
    for (int i = 1 ; i <= n ; i++) {
        if (!cnt[a[i]]) {
            for (int j = 1 ; j <= 26 ; j++) {
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
        else {
            int tmp = cnt[a[i]];
            while (l[a[i]] < i && tmp < d[i][a[i]]) {
                tmp = tmp + (a[l[a[i]]] == a[i] ? 1 : 0);
                l[a[i]]++;
            } 
            int diff = 0;
            for (int j = 0 ; j < 26 ; j++) {
                if (d[i - 1][j] - d[l[a[i]] - 1][j] > 0) diff++;
            }
            for (int j = 0 ; j <= diff ; j++) {
                dp[i][j + 1] += dp[i - 1][j];
            }
            for (int j = diff + 1 ; j <= 26 ; j++) {
                dp[i][j] += dp[i - 1][j];
            }
        }
        cnt[a[i]]++;
    }
    // for (int i = 1 ; i <= n ; i++) {
    //     for (int j = 1 ; j <= 4 ; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= 26 ; j++) {
            ans[j] += dp[i][j];
        }
    }
    for (int i = 1 ; i <= mp.size() ; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
/*
aabacaabbad
1 0 0 0 
2 0 0 0 
1 2 0 0 
1 3 0 0 
1 1 3 0 .
1 2 3 0 .
2 2 3 0 
1 2 5 0 
2 2 5 0 
3 4 3 0 
1 3 4 3 

*/