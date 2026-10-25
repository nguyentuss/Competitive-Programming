#include <iostream>
#include <algorithm>
#include <cmath>
#include <string> 
#include <vector>
#include <fstream>
using namespace std;

int dp[10007][10007];
vector <int> v;
int n , x;

void trace(int l, int r) {
    if (l == r) {
        cout << v[l] << " ";
        return;
    }

    if (v[l] == v[r]) {
        cout << v[l] << " ";
        trace(l+1,r-1);
        cout << v[r] << " ";
        return;
    }

    if (dp[l][r] == dp[l+1][r]) trace(l+1,r);
    else trace(l,r-1);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("daydx.inp","r",stdin);
    freopen("daydx.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n; i++) {
    	cin >> x;
    	v.push_back(x);
    }
    for(int len = 1; len <= n; len++)
        for(int l = 0; l < n - len + 1; l++) {
            int r = l + len - 1;

            if (len == 1) { dp[l][r] = 1; continue; }
            if (len == 2) { dp[l][r] = 1 + (v[l] == v[r]); continue; }

            dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
            if (v[l] == v[r]) dp[l][r] = max(dp[l][r], 2 + dp[l+1][r-1]);
        }
    cout << dp[0][n -1] << endl;
    trace(0, n-1);

    return 0;
}