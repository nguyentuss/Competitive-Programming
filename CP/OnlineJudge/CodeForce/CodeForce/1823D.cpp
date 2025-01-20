//source:: https://codeforces.com/contest/1823/problem/D
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
const int N = 27;
const int MOD = 1e9 + 7;

int x[N] , c[N];
int n , k;
// if we add one character we just only add one unique palindrome

void input() {
    cin >> n >> k;
    for (int i = 1 ; i <= k ; i++) cin >> x[i];
    for (int i = 1 ; i <= k ; i++) cin >> c[i];
    return;
}

// k just <= 20 , so we can use reverse character form 'z' to 'a';

bool write() {
    int sum = 0;
    for (int i = 1 ; i <= k ; i++) {
        if (c[i] > x[i]) return false;
        if (c[i] + sum > x[i]) return false;
        if (c[i] <= 2 && x[i] > c[i]) return false;
        sum = x[i] - (c[i] + sum);
        //cerr << sum << " ";
    }
    string s = "";
    int last = 0;
    bool change = 0;
    int tm = 'z';
    //cerr << "DEBUG";
    int cnt = 0;
    for (int i = 1 ; i <= k ; i++) {
        if (change == 1) {
            last = 0;
            if (c[i] - c[i - 1] > (x[i] - x[i - 1])) return false;
            for (int j = c[i - 1] + 1 ; j <= c[i] && ((int) s.size() < x[i])  ; j ++) {
                s += tm;
            }
            tm--;
        }
        else {
            bool ss = false;
            for (int j = c[i - 1] + 1 ; j <= c[i] - (3LL - last) && ((int) s.size() < x[i]) ; j++) {
                ss = true;
                s += tm;
            }
            if (ss) tm--;
        }
        while ((int) s.size() < x[i]) {
            if (change) {
                while (s.size() < x[i]) {
                    int tmp = cnt % 3;
                    tmp += 'a';
                    s += tmp;
                    cnt++;
                }
            }
            else {
                for (int j = (int)'a' + last ;
                j <= min((int)'c',(int)'a' + c[i] - 1) && ((int) s.size() < x[i]) ; j++) {
                    s += j;
                }
            }
        }
        //cerr << s << '\n';
        last = c[i];
        if (change == 0 && last >= 3) {
            change = 1;
            cnt = (int) s[(int) s.size() - 1]; 
            cnt -= 'a'; 
            cnt ++;
        }
        //cerr << s << '\n';
    }
    cout << "YES" << '\n';
    cout << s << '\n';
    return true;
}

void solve() {
    input();
    bool status = write(); 
    if (!status) cout << "NO\n";
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; cin >> test;
    while (test--) {
        solve();
    }
    //cerr << "DEBUG";
    return 0;
}