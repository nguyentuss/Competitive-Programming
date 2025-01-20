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

int a[N] , b[N]; 
int f[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ;i ++) {
        cin >> b[i];
        f[i] = -inf;
    }
    deque<ii> dq;
    a[0] = -inf;
    dq.push_back(ii(0 , 0));
    f[0] = 0;
    for (int i = 1 ; i <= n ;i ++) {
        int cxcuti = f[i - 1];
        while (!dq.empty() && a[dq.back().fi] >= a[i]) {
            cxcuti = max(cxcuti , dq.back().se);
            dq.pop_back();
        } 
        if (dq.back().fi > 0) f[i] = f[dq.back().fi];
        f[i] = max(f[i] ,cxcuti + b[i]);
        dq.push_back(ii(i , max(f[i] , cxcuti)));
    }
    cout << f[n];
    return 0;
}