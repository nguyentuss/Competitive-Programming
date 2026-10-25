#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (1e6 + 7)
vector<int> f(MAX_N , 0);
vector<int> a(MAX_N , 0);
int P[19][MAX_N];
int n , d;

int get(int l , int r) {
    int k = log2(r - l + 1);
    return min(P[k][l] , P[k][r - (1 << k) + 1]);
}

bool check(int x) {
    if (f[x] < d) return false;
    int l = 1 , r = x , cnt = 1;
    while (r <= n) {
        if ((f[x] + f[r] - f[x]) < cnt*d) return false;
        r++; cnt++;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    freopen("video.inp","r",stdin);
    freopen("video.out","w",stdout);
    cin >> n >> d;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
        P[0][i] = f[i];
    }
    int l = 0 , r = n;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r)/2;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans;

    return 0;
}

// chon thang thu i sao cho
// sum 1 -> i  = A

// A + a[i + 1] >= S*2  
// A + a[i + 1] + a[i + 2] >= S*3
// A + a[i + 1] + a[i + 2] + a[i + 3] >= S*4
// A + a[i + 1] + ... + a[n] >= S*(n - i)