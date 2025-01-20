//source:: https://codeforces.com/gym/103652/problem/B
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e6 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    cin >> test;
    while (test--) {
        int m , a , c , x0 , l1 , r1 , l2 , r2;
        cin >> m >> a >> c >> x0 >> l1 >> r1 >> l2 >> r2;
        int n = max(r1 , r2);
        vector<int> X(n + 1 , 0);
        for (int i = 1 ; i <= n ; i++) {
            X[i] = ((a*X[i - 1] + c) % m);
        }
        vector<int> sum()
    }
    return 0;
}