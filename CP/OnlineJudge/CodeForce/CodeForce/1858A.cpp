#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e9 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int a , b , c; cin >> a >> b >> c;
        a = a + c/2 + c%2;
        b = b + c/2;
        if (a - b >= 1) cout << "First" << '\n';
        else cout << "Second" << '\n';
    }
    return 0;
}