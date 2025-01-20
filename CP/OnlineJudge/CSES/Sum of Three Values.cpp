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
const int MAX_N = 5e3 + 7;
const int MOD = 1e9 + 7;

struct seg {
    int val , id;
};

bool cmp(seg &a , seg &b) {
    return a.val < b.val;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , x; cin >> n >> x;
    vector<seg> a(MAX_N);
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a.begin() + 1 , a.begin() + 1 + n , cmp);
    for (int i = 1 ; i <= n ; i++) {
        int l = 1;
        for (int j = i - 1 ; j >= 1 ; j--) {
            int sum = x - a[i].val - a[j].val;
            if (sum <= 0) continue;;
            while (l < j && a[l].val <= sum) {
                if (a[l].val == sum) {
                    cout << a[l].id << " " << a[j].id << " " << a[i].id;
                    return 0;
                }
                l++;
            }
        } 
    }
    cout << "IMPOSSIBLE";
    return 0;
}