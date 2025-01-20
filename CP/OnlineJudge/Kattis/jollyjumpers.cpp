//source:: https://open.kattis.com/problems/jollyjumpers
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
const int N = 3e3 + 7;
const int MOD = 1e9 + 7;


main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        int n;
        while (cin >> n) {
            vector<int> a(n);
            for (int i = 0 ; i < n ; i++) cin >> a[i];
            auto answer = [&]() -> bool {
                vector<int> c(n);
                for (int i = 0 ; i < n - 1 ; i++) {
                    if (abs(a[i] - a[i + 1]) > (n - 1)) return false;
                    c[abs(a[i] - a[i + 1])] ++;
                }
                for (int i = 1 ; i <= n - 1 ; i++) 
                    if (c[i] == false) return false;
                return true;
            };
            int status = answer();
            if (status) cout << "Jolly\n";
            else cout << "Not jolly\n";

        }
    }
    return 0;
}