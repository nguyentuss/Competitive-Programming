#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 5e3 + 7;
const int MOD = 1e9 + 7;

int a[N];
int f[N][N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , k , x; cin >> n >> k >> x;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    for (int i = 0 ; i <= n ; i++) {
        f[0][i] = -inf;
    }
    f[0][0] = 0;
    for (int i = 1 ; i <= x ; i++) {
        deque<int> dq;
        dq.push_back(i - 1);
        for (int j = 0 ; j <= n ; j++) {
            f[i][j] = -inf;
        }
        for (int j = i ; j <= n ; j++) {
            while (dq.size() && f[i - 1][dq.back()] <= f[i - 1][j]) 
                dq.pop_back();
            f[i][j] = f[i - 1][dq.front()] + a[j];
            
            while (dq.size() && dq.front() + k <= j) dq.pop_front();   
            dq.push_back(j);
        }
    }
    int ans = -1;
    //cout << f[x][n];
    for (int i = x ; i <= n ;i ++) {
        if (n - i + 1 <= k) {
            ans = max(ans , f[x][i]);
        }
    }
    cout << ans;
    return 0;
}