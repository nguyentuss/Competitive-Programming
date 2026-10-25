#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int N = 2e5 + 7;
const int inf = 1e18;
 
int f[N];
int lower[N];
int a[N];
 
main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , k , b , m; cin >> n >> a[1] >> k >> b >> m;
    lower[0] = inf;
    lower[1] = a[1];
    f[1] = 1;
    for (int i = 2 ; i <= n ; i++) {
        lower[i] = 1e9;
        a[i] = (k*a[i - 1] + b)%m;
        f[i] = 1;
        int l = 1 , r = i - 1;
        int pos = 0; 
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (lower[mid] < a[i]) {
                l = mid + 1;
                pos = mid;
            } 
            else r = mid - 1;
        }
        f[i] = max(f[i - 1] , pos + 1);
        lower[pos + 1] = min(lower[pos + 1] , a[i]);
    }
    cout << f[n];
    return 0;
}