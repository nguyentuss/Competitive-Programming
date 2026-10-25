#include <bits/stdc++.h>

using namespace std;

#define int long long

int calc(int u , int v) {
    // (x + y)*2 <= u 
    // => 2x + 2y <= u
    // => y <= u/2 - x
    int ans = 0;
    for (int i = 1 ; i * i <= v ; i++) {
        int tm1 = v/i , tm2 = u/2 - i;  
        ans = ans + max(0ll , min(tm1 , tm2) - i + 1);
    } 
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    //freopen("hall.inp","r",stdin);
    int a , b , c , d; cin >> a >> b >> c >> d;
    cout << calc(b , d) - calc(a - 1 , d) - calc(b , c - 1) + calc(a - 1 , c - 1); 

    return 0;
}