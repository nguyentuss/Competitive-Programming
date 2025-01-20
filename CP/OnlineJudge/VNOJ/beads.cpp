#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

int v[MAX_N] , lis[MAX_N] , revlis[MAX_N];

void LIS(int v[], int n, int res[]) {
    vector<int> last (n, 1e9 + 7);
    for(int i = 0; i < n; ++i) {
        res[i] = lower_bound(last.begin(), last.end(), v[i]) - last.begin();
        last[res[i]] = min(last[res[i]], v[i]);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int n , x; cin >> n;
    for (int i = 0 ;i < n ; i++) {
        cin >> v[i];
    }
    reverse(v , v + n);
    LIS(v , n , lis);
    for (int i = 0 ; i < n ; i++) 
        v[i] = -v[i];
    LIS(v , n , revlis);
    int ans = 0;
    for (int i = 0 ; i < n ;i++) {
        ans = max(ans , lis[i] + revlis[i] + 1);
    }
    cout << ans;
    return 0;
}