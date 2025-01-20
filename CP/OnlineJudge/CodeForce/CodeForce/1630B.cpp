#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e18 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

int a[MAX_N];
int b[MAX_N];
int n , k;
int ml , mr;
int ofl , ofr;

bool check(int x) {
    int l = 1 , r = 1;
    int cnt = 0;
    while (r <= n) {
        while ((b[r] - b[l]) > x && l <= r) l++;
        if (cnt < (r - l + 1)) {
            ml = b[l] , mr = b[r];
            cnt = r - l + 1;
        }
        r++;
    }
    int last = n - cnt;
    if ((cnt - last) >= k) {
        ofl = ml;
        ofr = mr;
        //cerr << x << " " << cnt << " " << last << '\n';
        return true;
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    int dem = 0;
    while (t--) {
        dem++;
        cin >> n >> k;
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b + 1 , b + 1 + n);
        int l = 0 , r = 1e9 , ans = 0;
        while (l <= r) {
            int mid = (l + r)>>1;
            if (check(mid)) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << ofl << " " << ofr << '\n';
        int sum = 0;
        l = 1;
        vector<ii> v;
        int groups = k;
        for (int i = 1 ; i <= n ; i++) {
            if (groups == 1) {
                cout << l << " " << n << '\n';
                break;
            }
            if (ofl <= a[i] and a[i] <= ofr) {
                sum++;
            }
            else {
                sum--;
            } 
            if (sum >= 1) {
                sum = 0;
                groups--;
                cout << l << " " << i << '\n';
                l = i + 1;
            }
        }
    }
    return 0;
}