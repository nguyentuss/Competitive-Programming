//source:: https://open.kattis.com/problems/inversefactorial
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    while (test--) {
        string s; cin >> s;
        int x = 1;
        for (int i = 1 ; i <= 10 ; i++) {
            x *= i;
            string tm = to_string(x); 
            if (tm == s) {
                cout << i;
                return 0;
            }
        }
        vector<double> f(N , 0);
        for (int i = 1 ; i < N ; i++) {
            f[i] = f[i - 1] + log10((double)i);
        }
        // for (int i = 1 ; i <= 30 ; i++) {
        //     cerr << (int)f[i] << " ";
        // }
        for (int i = 11 ; i < N ; i++) {
            if (s.size() == ((int)f[i] + 1)) {
                cout << i; 
                return 0;
            }
        }
    }
    return 0;
}