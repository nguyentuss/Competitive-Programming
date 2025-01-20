//source:: https://codeforces.com/gym/104777/problem/N
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
const int N = ;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    //cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<int> a(n);
        bitset<20> bt[n];
        for (int i = 0 ; i < n ; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        bitset<20> ans[n + 1];
        for (int num = 0; num < 20 ; num++) {
            for (int bit = 0 ; bit <= 1 ; bit++) {
                int cur = bit;
                for (int i = 0 ; i < n ; i++) {
                    if (cur == 0) {
                        if (b[i][num] == 0) {
                            ans[i + 1][num] = 0;
                            cur = 0;
                        }
                        if (b[i][num] == 1) {
                            ans[i + 1][num] = 1;
                        }
                    }

                }
            }
        }
    }
    return 0;
}