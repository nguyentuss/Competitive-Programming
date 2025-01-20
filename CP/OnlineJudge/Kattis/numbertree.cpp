//source:: https://open.kattis.com/problems/numbertree
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
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    //cin >> test;
    while (test--) {
        int H; cin >> H;
        string s; cin >> s;
        int cnt = 1;
        for (auto c : s) {
            if (c == 'L') cnt *= 2; 
            else cnt = cnt*2 + 1;
        }
        int pw2 = 1;
        for (int i = 0 ; i < H + 1 ; i++) {
            pw2 *= 2ll;
        }
        cout << pw2 - cnt;
    }
    return 0;
}