//source:: 
#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 107;
const int MOD = 1e9 + 7;

int f[N];
int a[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        int n; cin >> n;
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            f[i] = inf;
        }
        f[0] = 0; 
        for (int i = 0 ; i < n ; i++) {
            f[i + 1] = min(f[i + 1], f[i] + a[i + 1]);
            if (i + 2 <= n) 
                f[i + 2] = min(f[i + 2], f[i] + a[i + 2]);
        }
        cout << f[n];
    }
    return 0;
}