#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 2e6 + 7;
const int MOD = 1e9 + 7;

// NHỜ ANGEL ĐỘ CODE <3 , IU.

int n , a[MAX_N];

int calc(int lim) {
    int ans = 0 , diff = 0;
    unordered_map<int , int> cnt;
    int l = 1;
    for (int i = 1 ; i <= n ; i++) {
        if (!cnt[a[i]]) {
            diff ++;
        }   
        cnt[a[i]]++;
        if (diff <= lim) {
        }
        else {
            while (diff > lim) {
                cnt[a[l]] --;
                if (!cnt[a[l]]) diff--;
                l++;
            }
        }
        ans += (i - l + 1);
    }

    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int l , r; cin >> n >> l >> r;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
    }
    cout << calc(r) - calc(l - 1);
    return 0;
}