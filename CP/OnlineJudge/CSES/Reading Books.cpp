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
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a;
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x; 
        a.push_back(x);
        sum += x;
    }
    sort(a.begin() , a.end());
    cout << max(2*a[n - 1] , sum);
    return 0;
}