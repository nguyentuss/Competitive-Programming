//source:: 
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
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; test = 1;
    while (test--) {
        string st; 
        while (cin >> st) {
            auto solve = [&](string &st) -> void {
                int num = 0;
                for (char c : st) {
                    num += (c - '0');
                }
                int len = st.size();
                //cerr << num % len;
                if ((num % len) != 0) {
                    cout << st << ": invalid # of balls" << endl;
                    return;
                }   
                set<int> s;
                int cnt = 0;
                for (char c : st) {
                    c -= '0';
                    s.insert((c + cnt));
                    cnt++;
                }
                if (s.size() == st.size()) {
                    cout << st << ": valid with " << num/len << " balls\n";
                    return;
                }
                cout << st << ": invalid pattern\n";
                return;
            };
            solve(st);
        }
    }
    return 0;
}