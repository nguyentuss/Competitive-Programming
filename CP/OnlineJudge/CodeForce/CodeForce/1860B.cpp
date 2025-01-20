#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e8 + 7;
const int MOD = 1e9 + 7;

int m , k , a1 , ak; 

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int ans = 0;
        cin >> m >> k >> a1 >> ak;
        if (m % k >= a1)
        {
            int aaa = m %k;
            ans += aaa - a1;
            a1 = 0;
        }
        else a1 -= m%k;
        ans += max(0LL , m/k - ak - a1/k);
        cout << ans << '\n';
    }   
    return 0;
}