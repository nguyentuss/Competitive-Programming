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
const int MAX_N = 1e3;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n = 1000000000000000;
    int total = 0;
    int cnt = 0;
    while (n > 1) {
        cnt++;
        int tmp = sqrt(n);
        n = tmp;
        total += tmp;
    }
    cout << total << " " << cnt;
    return 0;
}   