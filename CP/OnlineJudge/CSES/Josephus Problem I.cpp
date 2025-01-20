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
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

int L[MAX_N];
int m[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        L[i] = i + 1;
        if (i == n) L[i] = 1;
    }
    int cnt = 0;
    int x = 1;
    int tmp;
    while (L[x] != x) {
        cnt++;
        if (cnt == 1) tmp = x;
        if (cnt == 2) {
            cnt = 0;
            cout << x << " ";
            m[x] = true;
            L[tmp] = L[x];
        }
        x = L[x];
    }
    for (int i = 1 ; i <= n ; i++) {
        if (!m[x]) {
            cout << x << " ";
            return 0;
        }
    }
    return 0;
}