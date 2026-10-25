#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int N = 2e5 + 7;
const int inf = 1e18;
 
int f[N];
int lower[N];
int P[N];
int cnt[N];
int a[N];
 
main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , k , b , m; cin >> n >> a[1] >> k >> b >> m;
    lower[0] = inf;
    lower[1] = a[1];
    cnt[lower[1]] = 1;
    P[1] = -1;
    f[1] = 1;
    for (int i = 2 ; i <= n ; i++) {
        P[i] = -1;
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
        f[i] = pos + 1;
        if (pos == 0) P[i] = -1;
        else P[i] = cnt[lower[pos]];
        if (lower[pos + 1] > a[i]) {
            lower[pos + 1] = a[i];
            cnt[lower[pos + 1]] = i;
        }
        //lower[pos + 1] = min(lower[pos + 1] , a[i]);
    }
    int ans = 0, pos = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (ans < f[i]) {
            ans = f[i];
            pos = i;
        }
    }   
    //cerr << pos;
    for (int i = 1 ; i <= n ; i++) cerr << P[i] << " ";
    vector<int> res;
    while (pos != -1) {
        res.push_back(a[pos]);
        pos = P[pos];
    }
    reverse(res.begin() , res.end());
    for (auto x : res) cout << x << " ";
    return 0;
}