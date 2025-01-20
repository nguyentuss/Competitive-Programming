#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e12 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , p , w , d; cin >> n >> p >> w >> d;
    for (int i = 0 ; i <= 1e7 ; i++) {
        if ((p - i*d)%w == 0 && (p - i*d)/w >= 0) {
            int tmp = (p - i*d)/w;
            if (tmp + i <= n) {
                cout << tmp << " " << i << " " << n - tmp - i << '\n';
                return 0; 
            }
        }
    }
    cout << -1;
    return 0;
}